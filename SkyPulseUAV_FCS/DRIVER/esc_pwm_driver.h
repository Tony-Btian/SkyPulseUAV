#ifndef ESC_PWM_DRIVER_H
#define ESC_PWM_DRIVER_H

#include <QObject>

#define PWM0 12
#define PWM1 13
#define PWM2 19
#define PWM3 18

class ESC_PWM_Driver : public QObject
{
    Q_OBJECT

public:
    ESC_PWM_Driver(QObject *parent = nullptr);

public slots:
    void setPwmSignal(int gpioPin, int dutyCycle);

private:
    void initial();

};

#endif // ESC_PWM_DRIVER_H
