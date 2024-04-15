#include <iostream>
#include <cmath>
#include <pigpio.h>
#include <array>

#include "MahonyFilter.h"

MahonyFilter::MahonyFilter() : MahonyFilter(sampleFreq, twoKpDef, twoKiDef) {};

MahonyFilter::MahonyFilter(float filterFreq, float twoPropGain, float twoInteGain) : 
	q{1.0f, 0.0f, 0.0f, 0.0f},
	mpu_data_ready(0),
	filter_ready_A(0),
	filter_ready_B(0),
	gx_out(0.0f),
	gy_out(0.0f),
	gz_out(0.0f),
	roll(0.0f),
	pitch(0.0f),
	yaw(0.0f),
	integralFBx(0.0f),
	integralFBy(0.0f),
	integralFBz(0.0f)
	{

    setFrequency(filterFreq);

    setKi(twoInteGain);

    setKp(twoPropGain);

	ax = ay = az = 0.0f;

	gx = gy = gz = 0.0f;

	mx = my = mz = 0.0f;

}

void MahonyFilter::readRawData(float a[3], float g[3], float m[3]) {
	
	mpu_data_ready = true;

	ax = a[0];
	ay = a[1];
	az = a[2];

	gx = g[0];
	gy = g[1];
	gz = g[2];

	gx_out.store(gx);
	gy_out.store(gy);
	gz_out.store(gz);

	// Correct for my personal magnet sensor placement, you can edit it accordingly.
	mx = m[1];
	my = -m[0];
	mz = m[2];

}

// Set parameter of filter.
void MahonyFilter::setFrequency(float f) {

    frequency = f;

}

void MahonyFilter::setKi(float twokiSet) {

    twoKi = twokiSet;

}

void MahonyFilter::setKp(float twokpSet) {

    twoKp = twokpSet;

}

// Check if the filter thread has received the data from IMU.
bool MahonyFilter::isDataReady() {

	return mpu_data_ready;

}

// Register callback functions 
void MahonyFilter::setCallbackA(CallbackFunction callback) {

	callbackA_ = callback;
	
}

void MahonyFilter::setCallbackB(CallbackFunction callback) {

	callbackB_ = callback;
	
}

// When new angles are ready, triggering callback functions.
std::array<float, 3> MahonyFilter::getAngleTest() {

	float rate[3] = {0};

	roll.store(atan2f( 2.0f * (q[2]* q[3] + q[1]*q[0]) , (  1.0f- 2.0f * (q[1]*q[1] + q[2]*q[2]) )) * 57.29578f);
	pitch.store(asinf( 2.0f * (q[1]*q[3] - q[2]*q[0])) * 57.29578f);
	yaw.store(atan2f( 2.0f * (q[1]*q[2] + q[3]*q[0]), ( 1.0f - 2.0f * (q[2]*q[2] + q[3]*q[3]) ) ) * 57.29578f);

	rate[0] = gx_out.load();
	rate[1] = gy_out.load();
	rate[2] = gz_out.load();

	if(callbackA_) {

		callbackA_(roll.load(), pitch.load(), yaw.load(), rate);

	}

	if(callbackB_) {

		callbackB_(roll.load(), pitch.load(), yaw.load(), rate);

	}

	return{roll.load(), pitch.load(), yaw.load()};
}

// Do filtering.
void MahonyFilter::MahonyAHRSupdate() {

	mpu_data_ready = false;

    float recipNorm;
	float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
	float hx, hy, bx, bz;
	float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	// Use IMU algorithm if magnetometer measurement invalid (avoids NaN in magnetometer normalisation)
	if ((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
		MahonyAHRSupdateIMU();
		return;
	}

	// Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
	if (!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {

		// Normalise accelerometer measurement
		recipNorm = invSqrt(ax * ax + ay * ay + az * az);
		ax *= recipNorm;
		ay *= recipNorm;
		az *= recipNorm;

		// Normalise magnetometer measurement
		recipNorm = invSqrt(mx * mx + my * my + mz * mz);
		mx *= recipNorm;
		my *= recipNorm;
		mz *= recipNorm;

		// Auxiliary variables to avoid repeated arithmetic
		q0q0 = q[0] * q[0];
		q0q1 = q[0] * q[1];
		q0q2 = q[0] * q[2];
		q0q3 = q[0] * q[3];
		q1q1 = q[1] * q[1];
		q1q2 = q[1] * q[2];
		q1q3 = q[1] * q[3];
		q2q2 = q[2] * q[2];
		q2q3 = q[2] * q[3];
		q3q3 = q[3] * q[3];

		// Reference direction of Earth's magnetic field
		hx = 2.0f * (mx * (0.5f - q2q2 - q3q3) + my * (q1q2 - q0q3) + mz * (q1q3 + q0q2));
		hy = 2.0f * (mx * (q1q2 + q0q3) + my * (0.5f - q1q1 - q3q3) + mz * (q2q3 - q0q1));
		bx = sqrt(hx * hx + hy * hy);
		bz = 2.0f * (mx * (q1q3 - q0q2) + my * (q2q3 + q0q1) + mz * (0.5f - q1q1 - q2q2));

		// Estimated direction of gravity and magnetic field
		halfvx = q1q3 - q0q2;
		halfvy = q0q1 + q2q3;
		halfvz = q0q0 - 0.5f + q3q3;
		halfwx = bx * (0.5f - q2q2 - q3q3) + bz * (q1q3 - q0q2);
		halfwy = bx * (q1q2 - q0q3) + bz * (q0q1 + q2q3);
		halfwz = bx * (q0q2 + q1q3) + bz * (0.5f - q1q1 - q2q2);

		// Error is sum of cross product between estimated direction and measured direction of field vectors
		halfex = (ay * halfvz - az * halfvy) + (my * halfwz - mz * halfwy);
		halfey = (az * halfvx - ax * halfvz) + (mz * halfwx - mx * halfwz);
		halfez = (ax * halfvy - ay * halfvx) + (mx * halfwy - my * halfwx);

		// Compute and apply integral feedback if enabled
		if (twoKi > 0.0f) {
			integralFBx += twoKi * halfex * (1.0f / sampleFreq);	// integral error scaled by Ki
			integralFBy += twoKi * halfey * (1.0f / sampleFreq);
			integralFBz += twoKi * halfez * (1.0f / sampleFreq);
			// integralFBx += twoKi * halfex;
			// integralFBy += twoKi * halfey;
			// integralFBz += twoKi * halfez;
			gx += integralFBx;	// apply integral feedback
			gy += integralFBy;
			gz += integralFBz;
		}
		else {
			integralFBx = 0.0f;	// prevent integral windup
			integralFBy = 0.0f;
			integralFBz = 0.0f;
		}

		// Apply proportional feedback
		gx += twoKp * halfex;
		gy += twoKp * halfey;
		gz += twoKp * halfez;
	}

	// Integrate rate of change of quaternion
	gx *= (0.5f * (1.0f / sampleFreq));		// pre-multiply common factors
	gy *= (0.5f * (1.0f / sampleFreq));
	gz *= (0.5f * (1.0f / sampleFreq));
	qa = q[0];
	qb = q[1];
	qc = q[2];
	q[0] += (-qb * gx - qc * gy - q[3] * gz);
	q[1] += (qa * gx + qc * gz - q[3] * gy);
	q[2] += (qa * gy - qb * gz + q[3] * gx);
	q[3] += (qa * gz + qb * gy - qc * gx);

	// Normalise quaternion
	recipNorm = invSqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
	q[0] *= recipNorm;
	q[1] *= recipNorm;
	q[2] *= recipNorm;
	q[3] *= recipNorm;

}

void MahonyFilter::MahonyAHRSupdateIMU() {

	mpu_data_ready = false;

    float recipNorm;
	float halfvx, halfvy, halfvz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	// Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
	if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {

		// Normalise accelerometer measurement
		recipNorm = invSqrt(ax * ax + ay * ay + az * az); 
		ax *= recipNorm;
		ay *= recipNorm;
		az *= recipNorm;        

		// Estimated direction of gravity
		halfvx = q[1] * q[3] - q[0] * q[2];
		halfvy = q[0] * q[1] + q[2] * q[3];
		halfvz = q[0] * q[0] - 0.5f + q[3] * q[3];
	
		// Error is sum of cross product between estimated and measured direction of gravity
		halfex = (ay * halfvz - az * halfvy);
		halfey = (az * halfvx - ax * halfvz);
		halfez = (ax * halfvy - ay * halfvx);

		// Compute and apply integral feedback if enabled
		if(twoKi > 0.0f) {
            // integral error scaled by Ki
			integralFBx += twoKi * halfex * (1.0f / frequency);	
			integralFBy += twoKi * halfey * (1.0f / frequency);
			integralFBz += twoKi * halfez * (1.0f / frequency);

            // apply integral feedback
			gx += integralFBx;	
			gy += integralFBy;
			gz += integralFBz;
		}
		else {
            // prevent integral windup
			integralFBx = 0.0f;	
			integralFBy = 0.0f;
			integralFBz = 0.0f;
		}

		// Apply proportional feedback
		gx += twoKp * halfex;
		gy += twoKp * halfey;
		gz += twoKp * halfez;
	}

	//std::cout << q[0] << "|" << q[1] << "|" << q[2] << "|" << q[3] << std::endl;

	// Integrate rate of change of quaternion
	gx *= (0.5f * (1.0f / frequency));		// pre-multiply common factors
	gy *= (0.5f * (1.0f / frequency));
	gz *= (0.5f * (1.0f / frequency));
	qa = q[0];
	qb = q[1];
	qc = q[2];
	q[0] += (-qb * gx - qc * gy - q[3] * gz); 
	q[1] += (qa * gx + qc * gz - q[3] * gy);
	q[2] += (qa * gy - qb * gz + q[3] * gx);
	q[3] += (qa * gz + qb * gy - qc * gx); 
	
	//std::cout << gx << "|" << gy << "|" << gz << std::endl;
	// Normalise quaternion
	recipNorm = invSqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
	q[0] *= recipNorm;
	q[1] *= recipNorm;
	q[2] *= recipNorm;
	q[3] *= recipNorm;

	//std::cout << recipNorm << std::endl;
}

float MahonyFilter::invSqrt(float x) {
	float halfx = 0.5f * x;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	return y;
}

// Get data from filter. If dont't want to read angle rate, put NULL there.
void MahonyFilter::getAngle(float* _roll, float* _pitch, float* _yaw, float angleRate[3]) {

	*_roll = atan2f( 2.0f * (q[2]* q[3] + q[1]*q[0]) , (  1.0f- 2.0f * (q[1]*q[1] + q[2]*q[2]) )) * 57.29578f;
	*_pitch = asinf( 2.0f * (q[1]*q[3] - q[2]*q[0])) * 57.29578f;
	*_yaw = atan2f( 2.0f * (q[1]*q[2] + q[3]*q[0]), ( 1.0f - 2.0f * (q[2]*q[2] + q[3]*q[3]) ) ) * 57.29578f;

	// If angle rate parameter is found.
	if(angleRate != NULL) {

		angleRate[0] = gx_out.load();
		angleRate[1] = gy_out.load();
		angleRate[2] = gz_out.load();

	}
	
	// roll.store(*_roll);
	// pitch.store(*_pitch);
	// yaw.store(*_yaw);
	
	filter_ready_A = 0;
	filter_ready_B = 0;

}

