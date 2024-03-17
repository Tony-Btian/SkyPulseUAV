#include "sensorreader.h"

SensorReader::SensorReader(I2C_Device *device,
                           int sensorId,
                           std::function<QByteArry> readFunc,
                           QObject *parent)
    : QObject(parent), device(device), sensorId(sensorId), readFunc(readFunc), shouldRun(0)
{
    threadPool.setMaxThreadCount(3); // Adjust the thread pool size as needed
}

void SensorReader::run()
{
    if(!isActive.load()) return;

    QByteArray data = readFunc();
    if(isActive.load()) {
        emit dataReady(sensorIdm, data);
    }
}

void SensorReader::startRead()
{
    isActive.store(1);
    QRunnable *task = new SensorReader(*this);
    threadPool.start(task);
}

void SensorReader::start()
{
    isActive.store(1);
}

void SensorReader::stop()
{
    isActive.store(0);
}
