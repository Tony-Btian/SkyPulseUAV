#include "i2cdriver.h"
#include <QDebug>

QMutex I2CDriver::mutex;

I2CDriver::I2CDriver(int deviceAddress, QObject *parent)
    : QObject(parent), deviceAddress(deviceAddress), handle(-1)
{
    if (!initialize()) {
        emit errorOccurred("Failed to open I2C device.");
    }
}

I2CDriver::~I2CDriver()
{
    if (handle >= 0) {
        i2cClose(handle);
    }
}

bool I2CDriver::initialize()
{
    QMutexLocker locker(&mutex);
    handle = i2cOpen(1, deviceAddress, 0);
    if (handle < 0) {
        qDebug() << "Failed to open I2C device:" << deviceAddress;
        return false;
    }
    qDebug() << "I2C Device Opened:" << QString::number(deviceAddress, 16);
    return true;
}

QByteArray I2CDriver::readBytes(quint8 registerAddress, quint8 count)
{
    QByteArray data(count, 0);  // Automating Memory Management with Qt Containers
    {
        QMutexLocker locker(&mutex);
        if (i2cReadI2CBlockData(handle, registerAddress, data.data(), count) == count) {
            return data;
        }
        else {
            qDebug() << "Failed to read from I2C device at register:" << registerAddress;
            emit errorOccurred("Failed to read from I2C device.");
            return QByteArray();
        }
    }
}

bool I2CDriver::writeBytes(quint8 registerAddress, const QByteArray &data)
{
    QMutexLocker locker(&mutex);
    if(i2cWriteI2CBlockData(handle, registerAddress, const_cast<char*>(data.data()), data.size()) == 0){
        return true;
    }
    else{
        qDebug() << "Failed to write to I2C device." << registerAddress;
        emit errorOccurred("Failed to write to I2C device.");
        return false;
    }
}

bool I2CDriver::writeByte(quint8 reg, quint8 value)
{
    QMutexLocker locker(&mutex);
    int result = i2cWriteByteData(handle, reg, value);
    if(result >= 0){
        return true;
    }
    return false;
}

bool I2CDriver::readByte(quint8 reg, quint8 &value)
{
    QMutexLocker locker(&mutex);
    int result = i2cReadByteData(handle, reg);
    if(result >= 0){
        value = result;
        return true;
    }
    return false;
}
