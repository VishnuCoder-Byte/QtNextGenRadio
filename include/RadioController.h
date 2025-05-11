#ifndef RADIOCONTROLLER_H
#define RADIOCONTROLLER_H

#include <QObject>
#include "DBusRadioReceiver.h"
#include "RadioModel.h"

class RadioController : public QObject {
    Q_OBJECT
public:
    explicit RadioController(QObject* parent = nullptr);

    void initialize();

    Q_INVOKABLE void receiveData(const QString& data) {
        qDebug() << "Received data from QML:" << data;
    }

private slots:
    void handleDataAdded(const QString& key, const QString& data);

private:
    DBusRadioReceiver m_receiver;
    RadioModel m_model;
};

#endif // RADIOCONTROLLER_H

