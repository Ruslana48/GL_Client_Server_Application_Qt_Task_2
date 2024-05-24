#include "server.h"

Server::Server(QObject *parent)
    : QObject(parent), tcpServer(new QTcpServer(this)), updateTimer(new QTimer(this)), m_nNextBlockSize(0) {
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
    connect(updateTimer, &QTimer::timeout, this, &Server::updateProcessList);
    updateTimer->start(10000);
}

void Server::startServer(const QString &ip, int port) {
    if (tcpServer->listen(QHostAddress(ip), port)) {
        qDebug() << "Server started at" << ip << ":" << port;
    } else {
        qDebug() << "Server failed to start:" << tcpServer->errorString();
    }
}

void Server::stopServer() {
    if (tcpServer->isListening()) {
        for (QTcpSocket *client : qAsConst(clients)) {
            sendToClient(client, "0");
            client->disconnectFromHost();
            if (client->state() != QAbstractSocket::UnconnectedState) {
                client->waitForDisconnected();
            }
        }
        clients.clear();
        tcpServer->close();
        qDebug() << "Server stopped";
    } else {
        qDebug() << "Error! Server was not running";
    }
}

QList<QTcpSocket *> Server::getClients() {
    return clients;
}

void Server::newConnection() {
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::gotDisconnection);
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readClientRequest);

    clients << clientSocket;

    sendToClient(clientSocket, "Reply: connection established");
    emit smbConnected();
    qDebug() << "New client connected";
}

void Server::readClientRequest() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_15);

    while (true) {
        if (m_nNextBlockSize == 0) {
            if (clientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (clientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }

        QString request;
        in >> request;
        m_nNextBlockSize = 0;

        emit gotNewMessage(request);
        qDebug() << "Read request: " << request.size();

        if (request == "request_process_list") {
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, [this]() {
                std::vector<ProcessInfo> processList = getProcessList();
                QString serializedProcessList;
                for (const ProcessInfo& process : processList) {
                    serializedProcessList += QString::fromStdString(process.pid) + "," +
                                             QString::fromStdString(process.command) + ";";
                }
                for (QTcpSocket *client : clients) {
                    sendToClient(client, QString("process_list %1").arg(serializedProcessList));
                }
            });
            timer->start(10000);
        } else if (request.startsWith("close_process ")) {
            qDebug() << request.size();
            QString pid = request.mid(14).trimmed();
            qDebug() << "Received close_process request with PID:" << pid;

            if (pid.isEmpty()) {
                qDebug() << "Error: PID is empty!";
                sendToClient(clientSocket, "process_closed failure");
                emit processClosed("failure");
                return;
            }

            bool success = closeProcess(pid);
            sendToClient(clientSocket, QString("process_closed %1").arg(success ? "success" : "failure"));
            emit processClosed(success ? "success" : "failure");
        }
    }
}

void Server::updateProcessList() {
    std::vector<ProcessInfo> processList = getProcessList();

    QString serializedProcessList;
    for (const ProcessInfo& process : processList) {
        serializedProcessList += QString::fromStdString(process.pid) + "," +
                                 QString::fromStdString(process.command) + ";";
    }

    emit processListUpdated(serializedProcessList);
}

std::vector<ProcessInfo> Server::getProcessList() {
    std::vector<ProcessInfo> processList;

    QDir procDir("/proc");
    if (!procDir.exists()) {
        qDebug() << "Error: Failed to open /proc";
        return processList;
    }

    QStringList processDirs = procDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QString &pid : processDirs) {
        bool ok;
        int pidNumber = pid.toInt(&ok);
        if (ok) {
            QFile cmdlineFile("/proc/" + pid + "/cmdline");
            if (cmdlineFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&cmdlineFile);
                QString command = in.readAll().trimmed();

                command.remove('\0');

                if (!command.isEmpty()) {
                    processList.push_back({pid.toStdString(), command.toStdString()});
                }
                cmdlineFile.close();
            }
        }
    }

    return processList;
}

void Server::gotDisconnection() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    clients.removeOne(clientSocket);
    emit smbDisconnected();
}

bool Server::closeProcess(const QString &pidStr) {
    bool ok;
    qint64 pidNumber = pidStr.toLongLong(&ok);
    qDebug() << "pid" << pidStr;
    if (ok) {
        if (kill(static_cast<pid_t>(pidNumber), SIGTERM) == -1) {
            qDebug() << "Error closing process with PID" << pidNumber << ":" << strerror(errno);
            return false;
        } else {
            qDebug() << "Closed process with PID:" << pidNumber;
            return true;
        }
    } else {
        qDebug() << "Invalid PID provided:" << pidStr;
        return false;
    }
}

qint64 Server::sendToClient(QTcpSocket *socket, const QString &str) {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out << quint16(0) << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    qDebug() << "Sending to client: " << str.size();
    return socket->write(arrBlock);
}
