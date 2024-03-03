#include <pigpio.h>
#include <iostream>
#include <math.h> 
#include <atomic>

#include "AttiDataCollect.hpp"
#include "MahonyAHRS.h"

extern MPU6050Data mpu6050Data;

volatile float twoKp = twoKpDef;											// 2 * proportional gain (Kp)
volatile float twoKi = twoKiDef;											// 2 * integral gain (Ki)
volatile float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;					// quaternion of sensor frame relative to auxiliary frame
volatile float integralFBx = 0.0f, integralFBy = 0.0f, integralFBz = 0.0f;	// integral error terms scaled by Ki

// wake mpu6050 up

void initializeOfMPU(int* handle, char* sample_rate, bool* needToExit) {

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (gpioInitialise() < 0) {
			std::cout << "pigpio is not ready!" << std::endl;
			*needToExit = true;
			return;
		}

		*handle = i2cOpen(IIC_BUS, MPU6050_ADDRESS, 0);  //sudo i2cdetect -y 1 to check addr

		if (*handle < 0) {
			std::cout << "I2C is not enabled!" << std::endl;
			gpioTerminate();
			*needToExit = true;
			return;
		}

	}

	char dataString[2] = {0x6B, 0};

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(*handle, dataString, sizeof(dataString)) != 0) {
			std::cout << "Can't wake MPU6050 up!" << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}
	
	char setSampleRate[2] = { 0x19, *sample_rate };  // sample rate = 8000 / (1+ sample_rate )
	
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(*handle, setSampleRate, sizeof(setSampleRate)) != 0) {
			std::cout << "Can't set sample rate!" << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}
}

// Magnet sensor initialization

void initializeOfMag(int* handle, bool* needToExit) {

	//if (gpioInitialise() < 0) {
	//	std::cout << "pigpio is not ready!" << std::endl;
	//	*needToExit = true;
	//	return;
	//}
	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		*handle = i2cOpen(IIC_BUS, GY_271_ADDRESS, 0);  //sudo i2cdetect -y 1 to check addr

		if (*handle < 0) {
			std::cout << "I2C is not enabled!" << std::endl;
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}

	/* Define set/reset period */

	char setPeriod[2] = { 0x0B, 0x01 };  

	/* Define OSR = 512, full range scale range = 8 Gauss, ODR = 200Hz, continuous measurement mode.*/

	char setDefaultConfig[2] = { 0x09, 0x1D };

	// check if data of Mag is ready 

	char statusRegister = 0x06;
	char status;

	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		if (i2cWriteDevice(*handle, setPeriod, sizeof(setPeriod)) != 0) {
			std::cout << "Set/reset period can't be running." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}


		if (i2cWriteDevice(*handle, setDefaultConfig, sizeof(setDefaultConfig)) != 0) {
			std::cout << "Can't set default config of GY-271." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}


		if (i2cWriteByte(*handle, statusRegister) != 0) {
			std::cout << "Can't access magnet sensor." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}

		if (i2cReadDevice(*handle, &status, 1) <= 0) {
			std::cout << "Can't read data from magnet sensor." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}

		if ((status & 0b00000001) != 1) {
			std::cout << "Status = " << (status & 0b00000001) << ", Magnet sensor is not ready." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}

	}

}

void initializeMPU6050Data(MPU6050Data& mpu6050Data) {

	mpu6050Data.ax.store(0.0f);
	mpu6050Data.ay.store(0.0f);
	mpu6050Data.az.store(0.0f);
	mpu6050Data.gx.store(0.0f);
	mpu6050Data.gy.store(0.0f);
	mpu6050Data.gz.store(0.0f);
	mpu6050Data.mx.store(0.0f);
	mpu6050Data.my.store(0.0f);
	mpu6050Data.mz.store(0.0f);

}

void initializeOfGPIO(bool* needToExit) {

	if (gpioInitialise() < 0) {
		std::cerr << "GPIO initialization failed." << std::endl;
		*needToExit = true;
		return;
	}

	gpioSetMode(INT_PIN, PI_INPUT);

	if (gpioSetISRFunc(INT_PIN, RISING_EDGE, 0, getAGMData) != 0) {
		std::cout << "mpu6050 int failed." << std::endl;
		*needToExit = true;
		return;
	}
}

// set full scale range of accelerometer to +-2g

void setRangeOfAcce(int handle, bool* needToExit) {

	char  dataAcce[2] = {0x1C, 0 << 3 };
	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		if (i2cWriteDevice(handle, dataAcce, sizeof(dataAcce)) != 0) {
			std::cout << "Can't set full scale range of accelerometer to +-2g" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}

}

// set full scale range of Gyroscope to +- 2000 °/s

void setRangeOfGyro(int handle, bool* needToExit) {

	char  dataGyro[2] = {0x1B, 3 << 3};

	{
		std::lock_guard<std::mutex> lock(i2cmtx);

		if (i2cWriteDevice(handle, dataGyro, sizeof(dataGyro)) != 0) {
			std::cout << "Can't set full scale range of Gyroscope to +-2g" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}
}

// Read data from Accelerometer and Gyroscope

void MPU6050ReadData(int handle, char* data, bool* needToExit) {

	char startAddr = 0x3B;
	int dataSize = 14;
	
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		
		if (i2cWriteByte(handle, startAddr) != 0) {
			std::cout << "Can't get data of accelerometer." << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}

		if (i2cReadDevice(handle, data, dataSize) <= 0) {
			std::cout << "Can't read data from accelerometer" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}
}

//// Read data from Gyroscope
//
//void gyroReadData(int handle, char* data, bool* needToExit, int dataSize) {
//	char gyroAddr = 0x43;
//
//	{
//		std::lock_guard<std::mutex> lock(i2cmtx);
//
//		if (i2cWriteByte(handle, gyroAddr) != 0) {
//			std::cout << "Can't get data of accelerometer." << std::endl;
//			i2cClose(handle);
//			gpioTerminate();
//			*needToExit = true;
//			return;
//		}
//
//		if (i2cReadDevice(handle, data, dataSize) <= 0) {
//			std::cout << "Can't read data from accelerometer" << std::endl;
//			i2cClose(handle);
//			gpioTerminate();
//			*needToExit = true;
//			return;
//		}
//	}
//}

// Read data from Magnet sensor

void magReadData(int handle, char* data, bool* needToExit, int dataSize) {
	char magAddr = 0x00;

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteByte(handle, magAddr) != 0) {
			std::cout << "Can't write address to magnet sensor." << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}

		if (i2cReadDevice(handle, data, dataSize) <= 0) {
			std::cout << "Can't read data from magnet sensor" << std::endl;
			i2cClose(handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}
}

void getAGMData(int GPIO, int level, unsigned int tick) {

	bool needToExit = false;
	
	// 0-5 acce, 6-7 temperature, 8-13 gyro.
	char MPU6050RawData[14]{};  
	MPU6050ReadData(handle_MPU6050, &MPU6050RawData[0], &needToExit);

	//char gyroData[6]{};
	//gyroReadData(handle_MPU6050, &gyroData[0], &needToExit);

	char magData[6]{};
	magReadData(handle_GY_271, &magData[0], &needToExit);

	if (needToExit) return;

	short ax, ay, az, gx, gy, gz, mx, my, mz;

	ax = ((MPU6050RawData[0] << 8) | MPU6050RawData[1]);
	ay = ((MPU6050RawData[2] << 8) | MPU6050RawData[3]);
	az = ((MPU6050RawData[4] << 8) | MPU6050RawData[5]);
	gx = ((MPU6050RawData[8] << 8) | MPU6050RawData[9]);
	gy = ((MPU6050RawData[10] << 8) | MPU6050RawData[11]);
	gz = ((MPU6050RawData[12] << 8) | MPU6050RawData[13]);
	mx = ((magData[0] << 8) | magData[1]);
	my = ((magData[2] << 8) | magData[3]);
	mz = ((magData[4] << 8) | magData[5]);

	//{
	//	std::unique_lock<std::shared_mutex> lock(sharedData.rawdata_mutex);
	//	// divide by 16384 so that the output is x times g.

	//	sharedData.ax = ax / 16384.0f;
	//	sharedData.ay = ay / 16384.0f;
	//	sharedData.az = az / 16384.0f;
	//	sharedData.gx = gx / 16.4f;
	//	sharedData.gy = gy / 16.4f;
	//	sharedData.gz = gz / 16.4f;

	//	// lack of pre-processing of data from magnet sensor
	//	sharedData.mx = mx;
	//	sharedData.my = my;
	//	sharedData.mz = mz;

	//	/*ready = sharedData.calibrate_ready;*/
	//}

	mpu6050Data.ax.store(ax / 16384.0f);
	mpu6050Data.ay.store(ay / 16384.0f);
	mpu6050Data.az.store(az / 16384.0f);
	mpu6050Data.gx.store(gx / 16.4f);
	mpu6050Data.gy.store(gy / 16.4f);
	mpu6050Data.gz.store(gz / 16.4f);
	mpu6050Data.mx.store(mx);
	mpu6050Data.my.store(my);
	mpu6050Data.mz.store(mz);
	
	mpu6050_newdata.store(true);
}

void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az) {
	float recipNorm;
	float halfvx, halfvy, halfvz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	// Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
	if (!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {

		// Normalise accelerometer measurement
		recipNorm = invSqrt(ax * ax + ay * ay + az * az);
		ax *= recipNorm;
		ay *= recipNorm;
		az *= recipNorm;

		// Estimated direction of gravity and vector perpendicular to magnetic flux
		halfvx = q1 * q3 - q0 * q2;
		halfvy = q0 * q1 + q2 * q3;
		halfvz = q0 * q0 - 0.5f + q3 * q3;

		// Error is sum of cross product between estimated and measured direction of gravity
		halfex = (ay * halfvz - az * halfvy);
		halfey = (az * halfvx - ax * halfvz);
		halfez = (ax * halfvy - ay * halfvx);

		// Compute and apply integral feedback if enabled
		if (twoKi > 0.0f) {
			integralFBx += twoKi * halfex * (1.0f / sampleFreq);	// integral error scaled by Ki
			integralFBy += twoKi * halfey * (1.0f / sampleFreq);
			integralFBz += twoKi * halfez * (1.0f / sampleFreq);
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
	qa = q0;
	qb = q1;
	qc = q2;
	q0 += (-qb * gx - qc * gy - q3 * gz);
	q1 += (qa * gx + qc * gz - q3 * gy);
	q2 += (qa * gy - qb * gz + q3 * gx);
	q3 += (qa * gz + qb * gy - qc * gx);

	// Normalise quaternion
	recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
	q0 *= recipNorm;
	q1 *= recipNorm;
	q2 *= recipNorm;
	q3 *= recipNorm;
}

void MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz) {
	float recipNorm;
	float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
	float hx, hy, bx, bz;
	float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	// Use IMU algorithm if magnetometer measurement invalid (avoids NaN in magnetometer normalisation)
	if ((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
		MahonyAHRSupdateIMU(gx, gy, gz, ax, ay, az);
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
		q0q0 = q0 * q0;
		q0q1 = q0 * q1;
		q0q2 = q0 * q2;
		q0q3 = q0 * q3;
		q1q1 = q1 * q1;
		q1q2 = q1 * q2;
		q1q3 = q1 * q3;
		q2q2 = q2 * q2;
		q2q3 = q2 * q3;
		q3q3 = q3 * q3;

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
	qa = q0;
	qb = q1;
	qc = q2;
	q0 += (-qb * gx - qc * gy - q3 * gz);
	q1 += (qa * gx + qc * gz - q3 * gy);
	q2 += (qa * gy - qb * gz + q3 * gx);
	q3 += (qa * gz + qb * gy - qc * gx);

	// Normalise quaternion
	recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
	q0 *= recipNorm;
	q1 *= recipNorm;
	q2 *= recipNorm;
	q3 *= recipNorm;
}

float invSqrt(float x) {
	float halfx = 0.5f * x;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	return y;
}