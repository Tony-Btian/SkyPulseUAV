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
    ~SensorReader();

    void run() override;
    void start();
    void stop();

private:
    I2C_Device* device;
    QThreadPool threadPool;
    QAtomicInt isActive;
    std::function<QByteArray()> readFunc;

    int sensorId;

signals:
    void dataReady(int sensorId, const QByteArray &data);
};

#endif // SENSORREADER_H
