#ifndef DECODETASK_H
#define DECODETASK_H

#include "MediatorInterface.h"
#include <QObject>
#include <QRunnable>
#include <QByteArray>

class DecodeTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit DecodeTask(const QByteArray &data, MediatorInterface *mediator);
    void run() override;

private:
    QByteArray dataToDecode;
    MediatorInterface* mediator; // 存储中介者的指针

    void decodeDataDistribution();

signals:
    void decodeDataReady(const QString &result);

};

#endif // DECODETASK_H
