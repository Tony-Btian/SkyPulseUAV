#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <QObject>
#include <QTimer>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <pigpio.h>
#include <QThread>

#include "observable.h"
#include "concretemediator.h"
#include "sensormanager.h"
#include "motorpwm.h"
#include "droneconfigmanager.h"
#include "flightcontrol.h"
#include "videostreamer.h"

/*COMM Head Files*/
#include "tcp.h"

class MainSystem : public QWidget, public Observable
{
    Q_OBJECT

public:
    MainSystem();
    ~MainSystem();


private:
    /* UI */

    /* Flight Control System */
    SensorManager *sensor_manager;
    MotorPWM *motor_pwm;
    FlightControl *flight_control;

    /* Network Protocol */
    TCP *tcp_server;

    /* Data Manager*/
    DroneConfigManager *configManager;

    /* Timer */
    QTimer *readTimer;
    bool timerRunning = false;

    /* Video Chapter */
    VideoStreamer *video_streamer;

    void UI_Initial();
    void GPIO_Initial();
    void Function_Initial();

public slots:
    void SetFlightControl(const QVector<uint8_t> &flight_control_data);
    void SetFlightConfigData(const QVector<quint8> &FlightCofig);
    void startTimer();
    void stopTimer();

private slots:
    void onButtonClicked_Function1();
    void onButtonClicked_Function2();
    void onButtonClicked_Function3();

    void onSpinBoxPitch_valueChanged(int value);
    void onSpinBoxYaw_valueChanged(int value);
    void onSpinBoxRoll_valueChanged(int value);
    void onSpinBoxThrust_valueChanged(int value);

    void toggleTimer();


signals:
    void sig_readAllSensorDataTest();
};

#endif // MAINSYSTEM_H
