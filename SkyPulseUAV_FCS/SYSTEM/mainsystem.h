#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include "observable.h"

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <pigpio.h>
#include <QThread>

#include "sensormanager.h"
#include "motorpwm.h"

/*COMM Head Files*/
#include "tcp.h"

class MainSystem : public QWidget, public Observable
{
    Q_OBJECT

public:
    MainSystem();
    ~MainSystem();

private slots:
    void onButtonClicked_Function1();
    void onButtonClicked_Function2();

private:
    QPushButton *function_button1, *function_button2;
    QHBoxLayout *layout;
    SensorManager *sensor_manager;
    MotorPWM *motor_pwm;

    /* Network Protocol */
    TCP *tcp_server;

    void UI_Initial();
    void GPIO_Initial();
    void Function_Initial();

signals:
    void sig_readAllSensorDataTest();
};

#endif // MAINSYSTEM_H
