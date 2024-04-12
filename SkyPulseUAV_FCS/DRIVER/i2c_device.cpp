#include "i2c_device.h"
#include <pigpio.h>
#include <QDebug>
#include <QThread>
#include <QByteArray>

QMutex I2C_Device::mutex; // Static mutex for synchronizing access across threads

I2C_Device::I2C_Device(int deviceAddress, QObject *parent)
    : QObject(parent), deviceAddress(deviceAddress), handle(-1) // Constructor initializes the device with an address and invalid handle
{
    if (!initialize()) { // Attempt to initialize the device
        emit errorOccurred("Failed to open I2C device."); // Emit error signal if initialization fails
    }
}

I2C_Device::~I2C_Device()
{
    if (handle >= 0) { // Check if handle is valid
        i2cClose(handle); // Close the I2C device if the handle is valid
    }
}

bool I2C_Device::initialize()
{
    QMutexLocker locker(&mutex); // Lock the static mutex to prevent concurrent access
    handle = i2cOpen(1, deviceAddress, 0); // Attempt to open the I2C device
    if (handle < 0) {
//        qDebug() << "Failed to open I2C device." << deviceAddress;
        return false;
    }
//    qDebug() << "I2C device opened " << deviceAddress;
    return true;
}

QByteArray I2C_Device::readBytes(quint8 registerAddress, quint8 count)
{
//    qDebug() << "I2C Running Thread: " << QThread::currentThreadId();
    QByteArray data(count, 0);  // Automating Memory Management with Qt Containers
    {
        QMutexLocker locker(&mutex); // Lock the static mutex to prevent concurrent access
        if (i2cReadI2CBlockData(handle, registerAddress, data.data(), count) == count) { // Attempt to read the specified number of bytes
            return data; // Return the read data if successful
        }
        else {
            qDebug() << "Failed to read from I2C device at register:" << registerAddress; // Log failure to read
            emit errorOccurred("Failed to read from I2C device."); // Emit error signal on read failure
            return QByteArray(); // Return an empty QByteArray on failure
        }
    }
}

bool I2C_Device::writeBytes(quint8 registerAddress, const QByteArray &data)
{
    QMutexLocker locker(&mutex); // Lock the static mutex to prevent concurrent access
    if(i2cWriteI2CBlockData(handle, registerAddress, const_cast<char*>(data.data()), data.size()) == 0){ // Attempt to write the byte array to the device
        return true; // Return true on successful write
    }
    else{
        qDebug() << "Failed to write to I2C device." << registerAddress; // Log failure to write
        emit errorOccurred("Failed to write to I2C device."); // Emit error signal on write failure
        return false; // Return false on failure
    }
}

bool I2C_Device::writeByte(quint8 reg, quint8 value)
{
    QMutexLocker locker(&mutex); // Lock the static mutex to prevent concurrent access
    int result = i2cWriteByteData(handle, reg, value); // Attempt to write a single byte to the device
    if(result >= 0){ // Check if the write operation was successful
        return true; // Return true on success
    }
    return false; // Return false on failure
}

bool I2C_Device::readByte(quint8 reg, quint8 &value)
{
    QMutexLocker locker(&mutex); // Lock the static mutex to prevent concurrent access
    int result = i2cReadByteData(handle, reg); // Attempt to read a single byte from the device
    if(result >= 0){ // Check if the read operation was successful
        value = result; // Assign the read value to the passed reference
        return true; // Return true on success
    }
    return false; // Return false on failure
}
