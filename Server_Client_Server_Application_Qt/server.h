#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <unistd.h>
#include <csignal>
#include <QHostAddress>
#include <QProcess>
#include <QDataStream>
#include <QRegularExpression>

struct ProcessInfo {
    std::string pid;
    std::string command;
};

class Server : public QObject {
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

    Q_INVOKABLE void startServer(const QString &ip, int port);
    Q_INVOKABLE void stopServer();
    QList<QTcpSocket *> getClients();
    std::vector<ProcessInfo> getProcessList();

signals:
    void smbConnected();
    void smbDisconnected();
    void processListUpdated(const QString &processList);
    void gotNewMessage(const QString &message);
    void processClosed(const QString &status);

private slots:
    void newConnection();
    void readClientRequest();
    void updateProcessList();
    void gotDisconnection();

private:
    bool closeProcess(const QString &pid);
    qint64 sendToClient(QTcpSocket *socket, const QString &str);

    QTcpServer *tcpServer;
    QTimer *updateTimer;
    QList<QTcpSocket *> clients;
    quint16 m_nNextBlockSize;
};

