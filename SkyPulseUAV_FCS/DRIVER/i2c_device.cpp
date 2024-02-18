#include "i2c_device.h"
#include <pigpio.h>
#include <QDebug>
#include <cstring>

QMutex I2C_Device::mutex;

I2C_Device::I2C_Device(int deviceAddress, QObject *parent)
    : QObject(parent), deviceAddress(deviceAddress), handle(-1)
{

}

I2C_Device::~I2C_Device()
{
    if (handle >= 0) {
        i2cClose(handle);
    }
}

bool I2C_Device::initialize()
{
    if (gpioInitialise() < 0) {
        qDebug() << "Failed to initialize pigpio.";
        return false;
    }
    mutex.lock();
    handle = i2cOpen(1, deviceAddress, 0);
    mutex.unlock();
    if (handle < 0) {
        qDebug() << "Failed to open I2C device.";
        return false;
    }
    return true;
}

QByteArray I2C_Device::readBytes(quint8 reg, quint8 count)
{
    char* buf = new char[count];
    QByteArray data;
    mutex.lock();
    if (i2cReadI2CBlockData(handle, reg, buf, count) == count) {
        data = QByteArray(buf, count);
    } else {
        qDebug() << "Failed to read from I2C device.";
    }
    mutex.unlock();
    delete[] buf;
    return data;
}

bool I2C_Device::writeBytes(quint8 reg, const QByteArray &data)
{
    mutex.lock();
    char* tempData = new char[data.size()];  // Creating a non-const temporary array
    memcpy(tempData, data.constData(), data.size());  // Copying the contents of a QByteArray to a temporary array
    bool success = i2cWriteI2CBlockData(handle, reg, tempData, data.size()) == 0;  // Calling Functions with Temporary Arrays
    mutex.unlock();

    delete[] tempData;  // Release the memory occupied by the temporary array
    if (!success) {
        qDebug() << "Failed to write to I2C device.";
    }
    return success;
}
