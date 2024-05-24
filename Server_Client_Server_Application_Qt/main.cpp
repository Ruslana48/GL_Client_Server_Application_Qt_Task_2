#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "server.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Server>("com.example.server", 1, 0, "Server");
    QQmlApplicationEngine engine;
    Server server;
    const QUrl url(QStringLiteral("qrc:/Server_Client_Server_Application_Qt/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
