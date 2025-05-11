#include "DBusRadioReceiver.h"
#include "DBusConnectionManager.h"

DBusRadioReceiver::DBusRadioReceiver(QObject* parent)
    : IIPCReceiver(parent) {}

void DBusRadioReceiver::initialize() {
    qDebug() << "Radio initialized";
    auto& bus = DBusConnectionManager::sessionBus();
    QString service = "org.example.RadioService";
    QString path = "/org/example/RadioService";
    QString interface = "org.example.RadioService";

    m_interface = new QDBusInterface("org.example.RadioService", "/org/example/RadioService",
                                         "", bus);
        if (!m_interface->isValid()) {
            qCritical() << "Failed to get RadioService interface";

            return;
        }

    bool success = bus.connect(service,path, interface, "dataChanged", this, SLOT(onDataChanged(QString, QString)));
    if (!success) {
        qCritical() << "Failed to connect to the signal.";
    } else {
        qDebug() << "Listening for dataAdded signal from RadioService...";
    }

    success = bus.connect(service,path, interface, "dataAdded", this, SLOT(onDataAdded(QString, QString)));
    if (!success) {
        qCritical() << "Failed to connect to the signal.";
    } else {
        qDebug() << "Listening for dataAdded signal from RadioService...";
    }
}

void DBusRadioReceiver::onDataChanged(const QString& key, const QString& data) {
    qDebug() << "[Radio] Presets:" << key;
    qDebug() << "[Radio] Sources:" << data;
    emit dataChanged(key,data);
}

void DBusRadioReceiver::onDataAdded(const QString& key, const QString& data) {
    qDebug() << "[Radio] Presets:" << key;
    qDebug() << "[Radio] Sources:" << data;
    emit dataAdded(key,data);
}

void DBusRadioReceiver::sendData(const QString& key, const QString& value) {
    if (m_interface && m_interface->isValid()) {
        QDBusReply<void> reply = m_interface->call("setData", key, value);
        if (!reply.isValid()) {
            qCritical() << "Failed to send data:" << reply.error().message();
        } else {
            qDebug() << "Data sent successfully.";
        }
    } else {
        qCritical() << "D-Bus interface is not valid.";
    }
}

