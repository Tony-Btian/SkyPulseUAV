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
    if(!isActive) return;

    QByteArray data = readFunc();
    if(isActive.loadRelaxed()) {
        emit dataReady(sensorId, data);
    }
}

void SensorReader::start()
{
    isActive.storeRelaxed(1);
    this->setAutoDelete(true);
    QThreadPool::globalInstance()->start(this);
}

void SensorReader::stop()
{
    isActive.storeRelaxed(0);
}
