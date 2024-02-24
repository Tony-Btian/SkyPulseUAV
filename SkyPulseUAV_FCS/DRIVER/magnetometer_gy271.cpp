#include "magnetometer_gy271.h"

#include <QtDebug>
#include <QtConcurrent>

Magnetometer_GY271::Magnetometer_GY271(I2C_Device *device, QObject *parent)
    : QObject(parent), device(device)
{

}

void Magnetometer_GY271::readRawData()
{
    QByteArray data = device->readBytes(0x03, 6);
    if (data.size() == 6) {
        int x = convertToRawData(data, 0);
        int y = convertToRawData(data, 2);
        int z = convertToRawData(data, 4);
        emit sig_rawDataRead(x, y, z);
    }
}

int16_t Magnetometer_GY271::convertToRawData(const QByteArray& bytes, int offset)
{
    int16_t value = static_cast<int16_t>((bytes[offset] << 8) | (bytes[offset + 1] & 0xFF));
    return value;
}
