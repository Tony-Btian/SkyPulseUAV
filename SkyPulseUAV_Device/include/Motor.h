#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR1_PIN 1
#define MOTOR2_PIN 2
#define MOTOR3_PIN 3
#define MOTOR4_PIN 4

#define MOTOR_FREQ 500.f

class Motor {

public:

    Motor();

    void setMotorRate();

    void readDutyCycle(int rateRequired[4]);

private:

    int motorDutyCycle[4];

};

#endif