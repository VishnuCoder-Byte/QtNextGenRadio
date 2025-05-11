#include "RadioModel.h"

RadioModel::RadioModel(QObject* parent)
    : QObject(parent) {}

void RadioModel::setData(const QString& key, const QString& data) {
    m_key = key;
    m_data = data;
    qDebug() << "[Model] Updated data -> Key:" << m_key << ", Data:" << m_data;
    emit currentChannelChanged();
}

QString RadioModel::currentChannel() const {
    qDebug() << " model data -> Key:"<<m_data ;
    return m_data;
}

QStringList RadioModel::sourceList() const {
    return m_sourceList;
}

