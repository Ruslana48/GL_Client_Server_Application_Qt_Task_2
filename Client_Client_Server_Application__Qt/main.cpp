#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "client.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Client client;

    QQmlApplicationEngine engine;
    qmlRegisterType<Client>("com.example", 1, 0, "Client");
    const QUrl url(QStringLiteral("qrc:/Client_Client_Server_Application__Qt/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
