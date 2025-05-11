#include "DBusMediaReceiver.h"
#include "DBusConnectionManager.h"

DBusMediaReceiver::DBusMediaReceiver(QObject* parent)
    : IIPCReceiver(parent) {}

void DBusMediaReceiver::initialize() {
    qDebug() << "initialized";
    auto& bus = DBusConnectionManager::sessionBus();
    QString service = "org.example.MediaService";
    QString path = "/org/example/Media";
    QString interface = "org.example.Media";


    bus.connect(service, path, interface, "SongList", this,
        SLOT(onSongListReceived(QStringList, QStringList, QStringList)));
}

void DBusMediaReceiver::onSongListReceived(const QStringList& names, const QStringList& artists, const QStringList& albumArts) {
    qDebug() << "[Media] Received song list:";
    for (int i = 0; i < names.size(); ++i) {
        qDebug() << names[i] << "by" << artists[i] << "| Art:" << albumArts[i];
    }
}
