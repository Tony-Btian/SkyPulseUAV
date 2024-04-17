#ifndef DECODETASK_H
#define DECODETASK_H

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

#include "MediatorInterface.h"

class DecodeTask : public QObject {

    Q_OBJECT

public:
    explicit DecodeTask();

private:
    QByteArray dataToDecode;
    MediatorInterface* mediator;
    void decodeDataDistribution();
    void decodeSensorData(QByteArray data_to_decode);

signals:
    void decodeDataReady(const QString &result);

};

#endif // DECODETASK_H
