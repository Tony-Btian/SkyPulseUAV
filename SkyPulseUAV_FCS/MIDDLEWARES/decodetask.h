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
    QByteArray data;
    QString decodeFunction(const QByteArray &data);

signals:
    void sig_ReadBMP180Registers_All();
};

#endif // DECODETASK_H
