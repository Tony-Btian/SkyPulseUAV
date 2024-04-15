#ifndef MOTORPWM_H
#define MOTORPWM_H

#include <QObject>
#include "pigpio.h"

#define PWM0 12
#define PWM1 13
#define PWM2 19
#define PWM3 18

class MotorPWM : public QObject
{
    Q_OBJECT

public:
    explicit MotorPWM(QObject *parent = nullptr);

public slots:
    void setMotorPWMSignal(const quint8 &motor1_dutycycle,
                           const quint8 &motor2_dutycycle,
                           const quint8 &motor3_dutycycle,
                           const quint8 &motor4_dutycycle);
//    void setPWM0Signal(const int &dutyCycle);
//    void setPWM1Signal(const int &dutyCycle);
//    void setPWM2Signal(const int &dutyCycle);
//    void setPWM3Signal(const int &dutyCycle);

private:
    void initialPWM();

signals:

};

#endif // MOTORPWM_H
