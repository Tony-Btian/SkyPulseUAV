#include "i2c_manager.h"
#include <QDebug>
#include <QFutureWatcher>

I2C_Manager::I2C_Manager(QObject *parent)
    : QObject(parent)
{

}

I2C_Manager::~I2C_Manager()
{
    qDeleteAll(devices);
}

I2C_Device* I2C_Manager::getDevice(int deviceAddress)
{
    return devices.value(deviceAddress, nullptr);
}

void I2C_Manager::addDevice(int deviceAddress)
{
    I2C_Device* device = new I2C_Device(deviceAddress, this);
    if (device->initialize()) {
        qDebug() << "Device" << deviceAddress << "initialized successfully.";
        devices.insert(deviceAddress, device);
    } else {
        qDebug() << "Failed to initialize device" << deviceAddress;
        delete device;
    }
}

void I2C_Manager::asyncReadSensorData(int deviceAddress, quint8 reg, quint8 count)
{
    I2C_Device* device = devices.value(deviceAddress, nullptr);
    if (device) {
        QFuture<QByteArray> future = QtConcurrent::run(readSensorData, device, reg, count);
        QFutureWatcher<QByteArray>* watcher = new QFutureWatcher<QByteArray>(this);
        connect(watcher, &QFutureWatcher<QByteArray>::finished, this, [this, watcher, deviceAddress, future]() {
            emit dataRead(deviceAddress, future.result());
            watcher->deleteLater();
        });
        watcher->setFuture(future);
    } else {
        qDebug() << "Device" << deviceAddress << "not found.";
    }
}

QByteArray I2C_Manager::readSensorData(I2C_Device* device, quint8 reg, quint8 count)
{
    return device->readBytes(reg, count);
}

