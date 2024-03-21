#include "sensorreader.h"

SensorReader::SensorReader(I2C_Device *device,
                           int sensorId,
                           std::function<QByteArray()> readFunc,
                           QObject *parent)
    : QObject(parent), device(device), sensorId(sensorId), readFunc(std::move(readFunc)), isActive(0)
{

}

SensorReader::~SensorReader()
{
    stop();
    QThreadPool::globalInstance()->waitForDone();
}

void SensorReader::run()
{
    if(!isActive.load()) return;

    QByteArray data = readFunc();
    if(isActive.load()) {
        emit dataReady(sensorId, data);
    }
}

void SensorReader::start()
{
    isActive.store(1);
    QThreadPool::globalInstance()->start(this);
}

void SensorReader::stop()
{
    isActive.store(0);
}
