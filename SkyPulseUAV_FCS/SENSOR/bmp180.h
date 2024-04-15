#ifndef BMP180_H
#define BMP180_H

#include <QObject>
#include "i2cdriver.h"

class BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit BMP180(uint8_t i2cAddress = 0x77, QObject *parent = nullptr);
    bool readCalibrationData();

public slots:
    void readPressure(double &pressure);
    void readTemperature(double &temperature);
    void readAllRegisters();

private:
    I2CDriver* i2cDriver;

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
    bool initializeBMP180();
    bool readShortFromRegister(uint8_t registerAddress, short &value);
    double calculatePressure(int rawPressure) const;

signals:
    void sig_pressureRead(double pressure);
    void sig_allRegistersData(const QByteArray &data);
    void sig_errorOccurred(const QString& message);

};

#endif // BMP180_H
