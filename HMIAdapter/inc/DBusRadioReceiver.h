#ifndef DBUSRADIORECEIVER_H
#define DBUSRADIORECEIVER_H

#include "IIPCReceiver.h"
#include <QDBusInterface>
#include <QDBusReply>

class DBusRadioReceiver : public IIPCReceiver {
    Q_OBJECT
public:
    explicit DBusRadioReceiver(QObject* parent = nullptr);
    void initialize() override;

    QDBusInterface *m_interface;

signals:
    void dataAdded(const QString& key, const QString& data);
    void dataChanged(const QString& key, const QString& data);


private slots:
    void onDataChanged(const QString& key, const QString& data);
    void onDataAdded(const QString& key, const QString& data);

    void sendData(const QString& key, const QString& value);
};

#endif // DBUSRADIORECEIVER_H
