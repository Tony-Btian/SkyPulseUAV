#include "motorpwm.h"
#include <QDebug>
#include <QThread>

MotorPWM::MotorPWM(QObject *parent)
    : QObject(parent)
{
    initialPWM();
    qWarning("Motor PWM Initialized");
    qDebug() << "Motor PWM Initialized Thread:" << QThread::currentThreadId();
}

void MotorPWM::initialPWM()
{
    uint8_t PWM[4] = {PWM0, PWM1, PWM2, PWM3};
    for(int i = 0; i < 4; i++){
        gpioSetMode(PWM[i], PI_OUTPUT);
        gpioSetPWMfrequency(PWM[i], 400);
        qDebug() << "PWM:" << PWM[i] << "Set";
    }
}

void MotorPWM::setMotorPWMSignal(const QVector<quint8> &Motor_PWM)
{
    QVector<quint8> gpioPins = {12, 13, 19, 18};  // It needs to correspond to the flight controller side.
    for (int i = 0; i < Motor_PWM.size(); i++){
        gpioPWM(gpioPins[i], Motor_PWM[i]);
    }
}

