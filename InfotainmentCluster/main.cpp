#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <DBusConnectionManager.h>
#include "DBusMediaReceiver.h"
#include "DBusRadioReceiver.h"
#include "RadioController.h"
#include "RadioModel.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    DBusMediaReceiver mediaReceiver;
    DBusRadioReceiver radioReceiver;
    RadioController radiocontroller;
    engine.rootContext()->setContextProperty("radioController", &radiocontroller);
    radiocontroller.initialize();

    RadioModel* radioModel = new RadioModel();
    engine.rootContext()->setContextProperty("radioModel", radioModel);

    mediaReceiver.initialize();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
