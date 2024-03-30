#ifndef DECODETASK_H
#define DECODETASK_H

#include <QObject>
#include <QRunnable>
#include <QByteArray>
#include <QThreadPool>

class DecodeTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit DecodeTask(const QByteArray &data);
    void run() override;

private:
    QByteArray dataToDecode;

signals:
    void decodeDataReady(const QString &result);

};

#endif // DECODETASK_H
