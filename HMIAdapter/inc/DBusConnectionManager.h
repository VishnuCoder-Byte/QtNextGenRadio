#ifndef DBUSCONNECTIONMANAGER_H
#define DBUSCONNECTIONMANAGER_H

#include <QDBusConnection>

class DBusConnectionManager {
public:
    static QDBusConnection& sessionBus() {
        static QDBusConnection conn = QDBusConnection::sessionBus();
        return conn;
    }
};

#endif // DBUSCONNECTIONMANAGER_H
