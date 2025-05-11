#ifndef RADIOMODEL_H
#define RADIOMODEL_H

#include <QObject>
#include <QString>
#include <QDebug>

class RadioModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList sourceList READ sourceList CONSTANT)
    Q_PROPERTY(QString currentChannel READ currentChannel NOTIFY currentChannelChanged)
public:
    explicit RadioModel(QObject* parent = nullptr);

    void setData(const QString& key, const QString& data);


    QStringList sourceList() const;
    QString currentChannel() const;

signals:
    void currentChannelChanged();

private:
    QString m_key;
    QString m_data;
    QStringList m_sourceList;
};

#endif // RADIOMODEL_H

