#include "client.h"

Client::Client(QObject *parent)
    : QObject(parent), tcpSocket(new QTcpSocket(this)), m_host(""), m_port(0), status(false) {
    timeoutTimer = new QTimer(this);
    timeoutTimer->setSingleShot(true);
    connect(timeoutTimer, &QTimer::timeout, this, &Client::connectionTimeout);

    connect(tcpSocket, &QTcpSocket::connected, this, &Client::handleConnected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::closeConnection);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::handleReadyRead);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred), this, &Client::handleError);
}

void Client::connectToServer() {
    timeoutTimer->start(3000);
    tcpSocket->connectToHost(m_host, m_port);
}

void Client::connectionTimeout() {
    if (tcpSocket->state() == QAbstractSocket::ConnectingState) {
        tcpSocket->abort();
        emit errorOccurred("Connection timed out");
        closeConnection();
    }
}

void Client::handleConnected() {
    status = true;
    timeoutTimer->stop();
    emit statusChanged();
}

void Client::closeConnection() {
    timeoutTimer->stop();
    if (tcpSocket->state() != QAbstractSocket::UnconnectedState) {
        tcpSocket->disconnectFromHost();
        if (tcpSocket->state() != QAbstractSocket::UnconnectedState) {
            tcpSocket->abort();
        }
    }
    status = false;
    emit statusChanged();
}

void Client::sendSignal(int pid, int signal) {
    if (kill(static_cast<pid_t>(pid), signal) == -1) {
        qDebug() << "Error with" << pid << ":" << strerror(errno);
    } else {
        qDebug() << "Closed process with PID:" << pid;
    }
}

void Client::requestProcessList(const QString &typeOfProcess, const int &pid) {
    if (tcpSocket->state() == QAbstractSocket::ConnectedState) {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_15);
        out << quint16(0);

        out << typeOfProcess;
        out.device()->seek(0);
        out << quint16(block.size() - sizeof(quint16));

        tcpSocket->write(block);
        qDebug() << "Sent request to server:" << typeOfProcess << "with PID:" << pid;
    } else {
        qDebug() << "Socket is not in connected state";
    }
}


void Client::closeProcess(const QString &pid) {
    if (tcpSocket->state() == QAbstractSocket::ConnectedState) {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_15);
        out << quint16(0);
        out << QString("close_process %1").arg(pid);
        out.device()->seek(0);
        out << quint16(block.size() - sizeof(quint16));

        tcpSocket->write(block);
        qDebug() << "Sent close_process request for PID:" << pid;
    }
}

void Client::handleReadyRead() {
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_15);

    static quint16 blockSize = 0;

    while (tcpSocket->bytesAvailable() > 0) {
        if (blockSize == 0) {
            if (tcpSocket->bytesAvailable() < sizeof(quint16)) {
                return;
            }
            in >> blockSize;
        }

        if (tcpSocket->bytesAvailable() < blockSize) {
            return;
        }

        QString response;
        in >> response;

        qDebug() << "Received response from server:" << response;

        if (response.startsWith("process_list ")) {
            QString processListData = response.mid(13);
            QStringList processEntries = processListData.split(";");
            QList<QVariantMap> processList;

            for (const QString &entry : processEntries) {
                QStringList details = entry.split(",");
                if (!details.isEmpty()) {
                    QVariantMap processMap;
                    processMap["pid"] = details.value(0);
                    processMap["processName"] = details.value(1);
                    processMap["args"] = details.value(2);
                    processList.append(processMap);
                } else {
                    qDebug() << "Invalid process entry:" << entry;
                }
            }

            QVariantList variantProcessList;
            for (const QVariantMap &process : processList) {
                variantProcessList.append(process);
            }

            emit processListReceived(variantProcessList);
        } else if (response.startsWith("process_closed ")) {
            QString result = response.mid(15);
            emit processClosed(result);
        }
        blockSize = 0;
    }
}

void Client::handleError(QAbstractSocket::SocketError socketError) {
    QString errorString;
    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
        errorString = "Connection was refused";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        errorString = "Remote host closed the connection";
        break;
    case QAbstractSocket::HostNotFoundError:
        errorString = "Host address was not found";
        break;
    case QAbstractSocket::SocketTimeoutError:
        errorString = "Connection timed out";
        break;
    default:
        errorString = "Unknown error";
    }
    emit errorOccurred(errorString);
    closeConnection();
}

QString Client::host() const { return m_host; }
void Client::setHost(const QString &hostAddress) { m_host = hostAddress; emit hostChanged(); }

int Client::port() const { return m_port; }
void Client::setPort(int portNumber) { m_port = portNumber; emit portChanged(); }

bool Client::getStatus() const { return status; }
QString Client::statusText() const { return status ? "Connected" : "Disconnected"; }
