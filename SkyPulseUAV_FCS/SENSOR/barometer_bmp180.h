#ifndef BAROMETER_BMP180_H
#define BAROMETER_BMP180_H

#include <QObject>
#include <QThread>
#include "i2c_device.h"

#define BMP180_DATAHEAD 0x15

class Barometer_BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit Barometer_BMP180(uint8_t i2cAddress = 0x77, QObject *parent = nullptr);
    bool readCalibrationData();

public slots:
    void readPressure();
    void readTemperature();
    void readAllRegisters();

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
    void sig_temperatureRead(double temperature);
    void sig_pressureRead(double pressure);
    void sig_allRegistersData(const QByteArray &data);
    void sig_errorOccurred(const QString& message);
};

#endif // BAROMETER_BMP180_H
