#ifndef MOTORPWM_H
#define MOTORPWM_H

#include <QObject>
#include <QVector>
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
    void setMotorPWMSignal(const QVector<quint8> &Motor_PWM);

private:
    void initialPWM();

signals:

};

#endif // MOTORPWM_H
