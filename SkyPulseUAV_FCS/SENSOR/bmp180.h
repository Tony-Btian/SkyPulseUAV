#ifndef BMP180_H
#define BMP180_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <cmath>
#include "i2cdriver.h"


/* Defination of OSS
 * OSS = 0; There was no oversampling and the measurement time was about 4.5 ms.
 * OSS = 1; The oversampling was done once and the measurement time was about 7.5 ms.
 * OSS = 2; The oversampling was done 2 times and the measurement time was about 13.5 ms.
 * OSS = 3;The oversampling was done 3 times and the measurement time was about 25.5 ms.
*/
#define OSS 1

/* Defination of WAIT_TIME:
 * Depending on the time mentioned above
*/
#define WAIT_TIME 8


class BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit BMP180(uint8_t i2cAddress = 0x77, QObject *parent = nullptr);
    void startPressureMeasurement(int oss);
    bool readCalibrationData();
    int16_t readRawTemperature();

public slots:
    void readPressure(double &pressure);
    void readTemperature(double &temperature);
    void readAllRegisters();

private:
    I2CDriver* i2cDriver;

    // Calibration coefficients
    short AC1;
    short AC2;
    short AC3;
    short AC4;
    short AC5;
    short AC6;
    short B1;
    short B2;
    short MB;
    short MC;
    short MD;

    // Utility functions
    bool initializeBMP180();
    bool readShortFromRegister(uint8_t registerAddress, short &value);
    double calculatePressure(int rawPressure);

signals:
    void sig_pressureRead(double pressure);
    void sig_allRegistersData(const QByteArray &data);
    void sig_errorOccurred(const QString& message);

};

#endif // BMP180_H
