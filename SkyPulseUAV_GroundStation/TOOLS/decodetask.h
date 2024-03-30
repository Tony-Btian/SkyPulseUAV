#ifndef DECODETASK_H
#define DECODETASK_H

#include <QObject>
#include <QRunnable>
#include <QByteArray>

class DecodeTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit DecodeTask(const QByteArray &data);
    void run() override;

private:
    QByteArray dataToDecode;
    void decodeDataDistribution();

signals:
    void decodeDataReady(const QString &result);

};

#endif // DECODETASK_H
