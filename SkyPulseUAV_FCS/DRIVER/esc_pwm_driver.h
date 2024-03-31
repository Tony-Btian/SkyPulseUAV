#ifndef ESC_PWM_DRIVER_H
#define ESC_PWM_DRIVER_H

#include "observer.h"
#include <QObject>

#define PWM0 12
#define PWM1 13
#define PWM2 19
#define PWM3 18

class ESC_PWM_Driver : public QObject, public Observer
{
    Q_OBJECT

public:
    ESC_PWM_Driver(QObject *parent = nullptr);
    void onUpdate(bool isInitialised) override;

public slots:
    void setPWM0Signal(const int &dutyCycle);

private:
    void initialPWM();

};

#endif // ESC_PWM_DRIVER_H
