#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <QThread>
#include <QCloseEvent>
#include <QDebug>
#include <pigpio.h>

/*Driver Head Files*/
#include "gpiointerrupthandler.h"
#include "esc_pwm_driver.h"
#include "i2c_device.h"

/*Middlewares Head Files*/
#include "tcp.h"

/*Sensor Head Files*/
#include "gyroacelemeter_gy521.h"
#include "magnetometer_gy271.h"
#include "barometer_bmp180.h"

/*Tools Head Files*/
#include "databasemanager.h"
#include "threadpool.h"
#include "observable.h"

#define HMC5883l_DEVICE_ADDR 0x0D


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observable
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void prepareForQuit();
    void readSensorData();

public slots:
    void callBackTest();

private slots:
    void on_pushButton_BMP_clicked();
    void on_pushButton_HMC_clicked();

private:
    Ui::MainWindow *ui;

    /* Thread */
    QThreadPool threadPool;
    QThread *BMP_Thread;

    /* Network Protocol */
    TCP *TCPServer;

    /* Sensors */
    MPU6050 *IMU;
    Barometer_BMP180 *BMP180;
    Magnetometer_GY271 *GY271;

    /* Driver */
    I2C_Device *device;
    ESC_PWM_Driver *PWMDriver;
    GpioInterruptHandler *gpiointerrupt;

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void sig_TCPBroadCastMessage(const QByteArray &message);
    void sig_readPressure();
    void sig_readTemperature();
    void sig_readDirection();

    // Read All Register to Ground Station.
    void sig_readAllRegisters_BMP180();

};
#endif // MAINWINDOW_H
