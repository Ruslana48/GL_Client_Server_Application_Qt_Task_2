#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QDataStream>
#include <QDebug>
#include <unistd.h>
#include <csignal>

// good
class Client : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(bool status READ getStatus NOTIFY statusChanged)
    Q_PROPERTY(QString statusText READ statusText NOTIFY statusChanged)

public:
    explicit Client(QObject *parent = nullptr);

    QString host() const;
    void setHost(const QString &hostAddress);

    int port() const;
    void setPort(int portNumber);

    bool getStatus() const;
    QString statusText() const; // good

    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void requestProcessList(const QString &typeOfProcess, const int &pid); // pass pid by copy
    Q_INVOKABLE void sendSignal(int pid, int signal);
    Q_INVOKABLE void closeProcess(const QString &pid);
    Q_INVOKABLE void closeConnection();

signals:
    void hostChanged();
    void portChanged();
    void statusChanged();
    void processListReceived(const QVariantList &processList);
    void processClosed(const QString &result);
    void errorOccurred(const QString &errorString);

private slots:
    void connectionTimeout();
    void handleConnected();
    void handleReadyRead();
    void handleError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *tcpSocket;
    QTimer *timeoutTimer;
    QString m_host;
    int m_port;
    bool status;
    QString pidToRemove;
};

