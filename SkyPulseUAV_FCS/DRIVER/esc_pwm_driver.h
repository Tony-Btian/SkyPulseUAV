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
    /**
 * @file   MyClass.h
 * @brief  这个文件包含了 MyClass 类的声明
 */
    ESC_PWM_Driver(QObject *parent = nullptr);

    /**
 * @file   MyClass.h
 * @brief  这个文件包含了 MyClass 类的声明
 */
    void onUpdate(bool isInitialised) override;

public slots:
    void setPWMSignal(int gpioPin, int dutyCycle);

private:
    void initialPWM();

};

#endif // ESC_PWM_DRIVER_H
