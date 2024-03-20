#ifndef BAROMETER_BMP180_H
#define BAROMETER_BMP180_H

#include <QObject>
#include "i2c_device.h"

#define BMP180_DEVICE_ADDR 0x77

class Barometer_BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit Barometer_BMP180(I2C_Device *i2cDevice, QObject *parent = nullptr);
    ~Barometer_BMP180();

public slots:
    void readPressure();

private:
    I2C_Device* i2cDevice;

    bool readCalibrationData();
    double calculatePressure(int rawPressure) const;

signals:
    void pressureRead(double pressure);
    void errorOccurred(const QString& message);
};

#endif // BAROMETER_BMP180_H
