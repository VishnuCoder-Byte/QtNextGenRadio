#include "RadioController.h"
#include <QDebug>

RadioController::RadioController(QObject* parent)
    : QObject(parent) {
    connect(&m_receiver, &DBusRadioReceiver::dataAdded,
            this, &RadioController::handleDataAdded);
    connect(&m_receiver, &DBusRadioReceiver::dataChanged,
            this, &RadioController::handleDataAdded);

    //connect(this, &RadioController::callbackChannel,
        //    &m_receiver, &DBusRadioReceiver::sendData);
}

void RadioController::initialize() {
    m_receiver.initialize();
}

void RadioController::handleDataAdded(const QString& key, const QString& data) {
    qDebug() << "[Controller] Received key:" << key << ", data:" << data;
    m_model.setData(key, data);
}

