#ifndef DECODETASK_H
#define DECODETASK_H

#include <QRunnable>
#include <QByteArray>

class DecodeTask : public QRunnable
{
public:
    explicit DecodeTask(const QByteArray &data); // Constructor to initialize the task with data
    void run() override; // Implementation of the QRunnable's run method

private:
    QByteArray data; // Holds the data to be decoded
    QString decode(const QByteArray &data); // Private method to decode the data
};

#endif // DECODETASK_H

