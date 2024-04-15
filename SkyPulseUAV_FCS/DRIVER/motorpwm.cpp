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

void MotorPWM::setMotorPWMSignal(const quint8 &motor1_dutycycle,
                                 const quint8 &motor2_dutycycle,
                                 const quint8 &motor3_dutycycle,
                                 const quint8 &motor4_dutycycle)
{
//    if((duty_cycle < 0) || (duty_cycle > 255)) return;
//    quint8 gpioPins[4] = {12, 13, 19, 18};
//    qDebug() << "Received Pin:" << pin;
    qDebug() << "Received PWM Value:" << motor1_dutycycle << motor2_dutycycle << motor3_dutycycle <<motor4_dutycycle;
    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
    gpioPWM(12, motor1_dutycycle);
    gpioPWM(13, motor2_dutycycle);
    gpioPWM(19, motor3_dutycycle);
    gpioPWM(18, motor4_dutycycle);
}

//void MotorPWM::setPWM0Signal(const int &dutyCycle)
//{
//    qDebug() << "Received PWM0 Value:" << dutyCycle;
//    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
//    if((dutyCycle < 0) || (dutyCycle > 255)) return;
//    gpioPWM(PWM0, dutyCycle);
//}

//void MotorPWM::setPWM1Signal(const int &dutyCycle)
//{
//    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
//    if((dutyCycle < 0) || (dutyCycle > 255)) return;
//    gpioPWM(PWM1, dutyCycle);
//}

//void MotorPWM::setPWM2Signal(const int &dutyCycle)
//{
//    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
//    if((dutyCycle < 0) || (dutyCycle > 255)) return;
//    gpioPWM(PWM2, dutyCycle);
//}

//void MotorPWM::setPWM3Signal(const int &dutyCycle)
//{
//    // Check the legitimacy of parameters, e.g. dutyCycle is usually in the range 0 to 255
//    if((dutyCycle < 0) || (dutyCycle > 255)) return;
//    gpioPWM(PWM3, dutyCycle);
//}
