#include "i2c_device.h"
#include <pigpio.h>
#include <QDebug>
#include <QThread>
#include <QByteArray>

QMutex I2C_Device::mutex;

I2C_Device::I2C_Device(int deviceAddress, QObject *parent)
    : QObject(parent), deviceAddress(deviceAddress), handle(-1)
{
    if (!initialize()) {
        emit errorOccurred("Failed to open I2C device.");
    }
}

I2C_Device::~I2C_Device()
{
    if (handle >= 0) {
        i2cClose(handle);
    }
}

bool I2C_Device::initialize()
{
    QMutexLocker locker(&mutex);
    handle = i2cOpen(1, deviceAddress, 0);
    if (handle < 0) {
        qDebug() << "Failed to open I2C device.";
        return false;
    }
    return true;
}

QByteArray I2C_Device::readBytes(quint8 reg, quint8 count)
{
    qDebug() << "I2C Device Thread: " << QThread::currentThreadId();
    QByteArray data(count, 0);  // Automating Memory Management with Qt Containers
    mutex.lock();
    if (i2cReadI2CBlockData(handle, reg, data.data(), count) == count) {
        mutex.unlock();
        return data;
    }
    else {
        qDebug() << "Failed to read from I2C device.";
        mutex.unlock();
        emit errorOccurred("Failed to read from I2C device.");
        return QByteArray();
    }
}

bool I2C_Device::writeBytes(quint8 reg, QByteArray data)
{
    QMutexLocker locker(&mutex);
    if(i2cWriteI2CBlockData(handle, reg, data.data(), data.size()) == 0){
        return true;
    }
    else{
        qDebug() << "Failed to write to I2C device.";
        emit errorOccurred("Failed to write to I2C device.");
        return false;
    }
}
