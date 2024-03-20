#ifndef SENSORREADER_H
#define SENSORREADER_H

#include <QObject>
#include <QRunnable>
#include <functional>
#include <QByteArray>
#include <QAtomicInt>
#include <QThreadPool>
#include "i2c_device.h"

class SensorReader : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit SensorReader(I2C_Device* device,
                          int sensorId,
                          std::function<QByteArray()> readFunc,
                          QObject *parent = nullptr
                          /*std::function<void(const QByteArray&)> callback*/);

    void run() override;
    void startRead();
    void start();
    void stop();

private:
    I2C_Device* device;
    QThreadPool threadPool;

    std::function<QByteArray()> readFunc;
//    std::function<void(const QByteArray&)> callback;
    QAtomicInt isActive;

    int sensorId;

signals:
    void dataReady(int sensorId, const QByteArray &data);
};

#endif // SENSORREADER_H
