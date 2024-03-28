#ifndef BAROMETER_BMP180_H
#define BAROMETER_BMP180_H

#include <QObject>
#include <QThread>
#include "i2c_device.h"

class Barometer_BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit Barometer_BMP180(uint8_t i2cAddress = 0x77, QObject *parent = nullptr);
    bool readCalibrationData();

public slots:
    void readPressure();
    void readTemperature();

private:
    I2C_Device* i2cDevice;

    // Calibration coefficients
    short ac1;
    short ac2;
    short ac3;
    short ac4;
    short ac5;
    short ac6;
    short b1;
    short b2;
    short mb;
    short mc;
    short md;

    // Utility functions
    bool readShortFromRegister(uint8_t registerAddress, short &value);
    double calculatePressure(int rawPressure) const;

signals:
    void temperatureRead(double temperature);
    void pressureRead(double pressure);
    void errorOccurred(const QString& message);
};

#endif // BAROMETER_BMP180_H
