#ifndef MAGNETOMETER_GY271_H
#define MAGNETOMETER_GY271_H

#include <QObject>
#include <QByteArray>
#include <QMutex>
#include <QMutexLocker>
#include "i2c_device.h"

class Magnetometer_GY271 : public QObject
{
    Q_OBJECT

public:
    explicit Magnetometer_GY271(I2C_Device *device, QObject *parent = nullptr);
    void readRawData();

private:
    I2C_Device *device;
    QMutex mutex;

    int16_t convertToRawData(const QByteArray &bytes, int offset);

private slots:
    void handleI2CError(QString error);

signals:
    void sig_rawDataRead(int x, int y, int z);

};

#endif // MAGNETOMETER_GY271_H
