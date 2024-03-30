#ifndef DECODETASK_H
#define DECODETASK_H

#include <QRunnable>
#include <QByteArray>

class DecodeTask : public QRunnable
{

public:
    explicit DecodeTask(const QByteArray &data);
    void run() override;

private:
    QByteArray data;
    QString decode(const QByteArray &data);
};

#endif // DECODETASK_H
