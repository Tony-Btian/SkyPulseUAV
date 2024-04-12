#ifndef MAGNETOMETER_GY271_H
#define MAGNETOMETER_GY271_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include "i2c_device.h"

class Magnetometer_GY271 : public QObject
{
    Q_OBJECT

public:
    explicit Magnetometer_GY271(uint8_t i2cAddress = 0x0D, QObject *parent = nullptr);
    bool initializeGY271();

public slots:
    void readRawData();

private:
    I2C_Device *i2cDevice;
    bool writeByte(uint8_t reg, uint8_t value);
    int16_t convertToRawData(const QByteArray &bytes, int offset);

private slots:
    void handleI2CError(QString error);

signals:
    void sig_rawDataRead(int x, int y, int z);
    void sig_errorOccurred(const QString&error);
};

#endif // MAGNETOMETER_GY271_H
