#ifndef BAROMETER_BMP180_H
#define BAROMETER_BMP180_H

#include <QObject>
#include <atomic>
#include "i2c_device.h"

#define BMP180_DEVICE_ADDR 0x77

class Barometer_BMP180 : public QObject
{
    Q_OBJECT

public:
    explicit Barometer_BMP180(QObject *parent = nullptr);
    ~Barometer_BMP180();

private:
    I2C_Device *i2cdevice;
    std::atomic<bool> shouldStop{false};

    static long B5;

    void calculateTemperature(int UT);
    void calculatePressure(int UP);

public slots:
    void readTemperatureData();
    void readPressureData();
    void readingStop();

signals:
    void sig_temperatureRead(double temperature);
    void sig_pressureRead(double pressure);
    void error(QString err);

};

#endif // BAROMETER_BMP180_H
