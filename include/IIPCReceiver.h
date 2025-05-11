#ifndef IIPCRECEIVER_H
#define IIPCRECEIVER_H

#include <QObject>
#include <QStringList>
#include <QDebug>

class IIPCReceiver : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;
    virtual void initialize() = 0;
};

#endif // IIPCRECEIVER_H
