#include "pidcontroller.h"

PIDController::PIDController(float kp, float ki, float kd)
    : kp_(kp), ki_(ki), kd_(kd), integral_(0), last_error_(0), target_(0) {}

void PIDController::setTarget(float target) {
    target_ = target;
}

void PIDController::setKp(float kp) {
    kp_ = kp;
}

void PIDController::setKi(float ki) {
    ki_ = ki;
}

void PIDController::setKd(float kd) {
    kd_ = kd;
}

float PIDController::update(float current, float dt) {
    float error = target_ - current;
    integral_ += error * dt;
    float derivative = (error - last_error_) / dt;
    last_error_ = error;
    return (kp_ * error) + (ki_ * integral_) + (kd_ * derivative);
}
