#include "barometer_bmp180.h"
#include <QDebug>
//#include <QThread>
#include <QtConcurrent>

long Barometer_BMP180::B5;

// Adjustable via TCP communication
short AC1 = 408, AC2 = -72, AC3 = -14383;
unsigned short AC4 = 32741, AC5 = 32757, AC6 = 23153;
short B1 = 6190, B2 = 4, MB = -32768, MC = -8711, MD = 2868;


Barometer_BMP180::Barometer_BMP180(QObject *parent)
    : QObject(parent),
      _stop(0)
{
    i2cdevice = new I2C_Device(BMP180_DEVICE_ADDR, this);
//    connect(&watcher, &QFutureWatcher<void>::finished, this, &Mahony_Plot::plotThreadParameterInitial);
}

Barometer_BMP180::~Barometer_BMP180()
{
    if (watcher.isRunning()) {
        watcher.waitForFinished();
    }
    delete i2cdevice;
}

void Barometer_BMP180::readingStop()
{
//    shouldStop = true;
    _stop.storeRelease(1);
}

void Barometer_BMP180::readTemperatureData()
{
    if (!i2cdevice) {
        qDebug() << "I2C device is not initialized.";
        return;
    }
//    while(!shouldStop){
//        // Read raw temperature data
//        i2cdevice->writeBytes(0xF4, QByteArray(1, 0x2E)); // Write Temperature Measurement Command
//        QThread::msleep(500); // Waiting for conversion time
//        QByteArray tempRawData = i2cdevice->readBytes(0xF6, 2); // Reading temperature data
//        if (tempRawData.size() == 2) {
//            int UT = static_cast<unsigned char>(tempRawData[0]) << 8 | static_cast<unsigned char>(tempRawData[1]);
//            calculateTemperature(UT);
//        } else {
//            qDebug() << "Invalid temperature data received.";
//        }
//        if (shouldStop.load()) { // If the external request stops, jump out of the loop
//            break;
//        }
//    }
    auto future = QtConcurrent::run([this]() {
        int i = 0;
        while (_stop.loadAcquire() == 0) {
            i2cdevice->writeBytes(0xF4, QByteArray(1, 0x2E)); // Write Temperature Measurement Command
            QThread::msleep(100); // Waiting for conversion time
            QByteArray tempRawData = i2cdevice->readBytes(0xF6, 2); // Reading temperature data
            if (tempRawData.size() == 2) {
                int UT = static_cast<unsigned char>(tempRawData[0]) << 8 | static_cast<unsigned char>(tempRawData[1]);
                calculateTemperature(UT);
            } else {
                qDebug() << "Invalid temperature data received.";
            }
        }
    });
    watcher.setFuture(future);
}

void Barometer_BMP180::readPressureData()
{
    if (!i2cdevice) {
        qDebug() << "I2C i2cdevice is not initialized.";
        return;
    }

    auto future = QtConcurrent::run([this]() {
        while (_stop.loadAcquire() == 0) {
            qDebug() << "BMP Thread ID: " << QThread::currentThreadId();
            // Read raw barometric pressure data
            i2cdevice->writeBytes(0xF4, QByteArray(1, 0x34 + (3 << 6))); // Write barometric command
            QThread::msleep(100); // Waiting for conversion time
            QByteArray pressureRawData = i2cdevice->readBytes(0xF6, 3); // Reading air pressure data
            if (pressureRawData.size() == 3) {
                int UP = (static_cast<unsigned char>(pressureRawData[0]) << 16 | static_cast<unsigned char>(pressureRawData[1]) << 8 | static_cast<unsigned char>(pressureRawData[2])) >> (8 - 3);
                calculatePressure(UP);
            } else {
                qDebug() << "Invalid pressure data received.";
            }
        }
    });
    watcher.setFuture(future);
}

void Barometer_BMP180::calculateTemperature(int UT)
{
    long X1 = (UT - AC6) * AC5 / 32768;
    long X2 = MC * 2048 / (X1 + MD);
    long B5 = X1 + X2;
    float temperature = (B5 + 8) / 16.0f / 10;
    qDebug() << temperature << " in Thread: " << QThread::currentThreadId();
    emit sig_temperatureRead(temperature);
}

void Barometer_BMP180::calculatePressure(int UP)
{
    // Here you need to use the B5 value obtained from the calculateTemperature calculation,
    // so you may need to save B5 as a member variable

    long X1, X2, X3, B3, B6, pressure;
    unsigned long B4, B7;

    B6 = B5 - 4000;
    X1 = (B2 * (B6 * B6 / 4096)) / 2048;
    X2 = AC2 * B6 / 2048;
    X3 = X1 + X2;
    B3 = (((AC1 * 4 + X3) << 3) + 2) / 4;

    X1 = AC3 * B6 / 8192;
    X2 = (B1 * (B6 * B6 / 4096)) / 65536;
    X3 = ((X1 + X2) + 2) / 4;
    B4 = AC4 * (unsigned long)(X3 + 32768) / 32768;
    B7 = ((unsigned long)UP - B3) * (50000 >> 3);

    if (B7 < 0x80000000) {
        pressure = (B7 * 2) / B4;
    } else {
        pressure = (B7 / B4) * 2;
    }

    X1 = (pressure / 256) * (pressure / 256);
    X1 = (X1 * 3038) / 65536;
    X2 = (-7357 * pressure) / 65536;
    pressure = pressure + (X1 + X2 + 3791) / 16;
    qDebug() << pressure;
    emit sig_pressureRead(pressure);
}

void Barometer_BMP180::waitForThreadCompletion() {
    if (watcher.isRunning()) {
        watcher.waitForFinished();
    }
}
