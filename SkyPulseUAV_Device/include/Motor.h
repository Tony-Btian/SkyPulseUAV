#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR1_PIN 1
#define MOTOR2_PIN 2
#define MOTOR3_PIN 3
#define MOTOR4_PIN 4

#define MOTOR_FREQ 500.f
#define MOTOR_RANGE 10000
#define MOTOR_HALF_RANGE 5000

class Motor {

public:

    Motor();

    void updateMotor(int rateRequired[4]);

private:

    int motorDutyCycle[4];
    bool beyondRange[4];

};

#endif