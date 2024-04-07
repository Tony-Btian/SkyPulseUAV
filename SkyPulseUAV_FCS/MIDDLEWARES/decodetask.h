#ifndef DECODETASK_H
#define DECODETASK_H

#include <QObject>
#include <QRunnable>
#include <QByteArray>
#include "Mediatorinterface.h"

class DecodeTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit DecodeTask(const QByteArray &data, MediatorInterface* mediator);
    void run() override;

private:
    QByteArray dataToDecode;
    MediatorInterface *mediator;
    void decodeDataDistribution();

signals:
    void decodeDataReady(const QString &result);
};

#endif // DECODETASK_H
