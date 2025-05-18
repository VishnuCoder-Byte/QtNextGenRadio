#ifndef DBUSMEDIARECEIVER_H
#define DBUSMEDIARECEIVER_H

#include "IIPCReceiver.h"
#include <QDBusInterface>
#include <QDBusMessage>

class DBusMediaReceiver : public IIPCReceiver {
    Q_OBJECT
public:
    explicit DBusMediaReceiver(QObject* parent = nullptr);
    void initialize() override;

private slots:
    void onSongListReceived(const QStringList& names, const QStringList& artists, const QStringList& albumArts);
};

#endif // DBUSMEDIARECEIVER_H
