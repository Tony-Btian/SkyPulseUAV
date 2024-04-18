#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H


class PIDController
{
public:
    PIDController(float kp, float ki, float kd);
    void setTarget(float target);
    void setKp(float kp);
    void setKi(float ki);
    void setKd(float kd);
    float update(float current, float dt);

private:
    float kp_; // Proportional gain
    float ki_; // Integral gain
    float kd_; // Derivative gain

    float integral_; // Integral sum
    float last_error_; // Last error value
    float target_; // Target setpoint
};

#endif // PIDCONTROLLER_H
