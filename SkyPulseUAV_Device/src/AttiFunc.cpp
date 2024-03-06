#include <pigpio.h>
#include <iostream>
#include <math.h> 
#include <atomic>

#include "AttiDataCollect.hpp"
#include "MahonyAHRS.h"

extern MPU6050Data mpu6050Data;

volatile float twoKp = twoKpDef;											// 2 * proportional gain (Kp)
volatile float twoKi = twoKiDef;											// 2 * integral gain (Ki)
// volatile float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q[3] = 0.0f;					// quaternion of sensor frame relative to auxiliary frame
volatile float integralFBx = 0.0f, integralFBy = 0.0f, integralFBz = 0.0f;	// integral error terms scaled by Ki

// wake mpu6050 up

void initializeMPU(int* handle, char* sample_rate, bool* needToExit) {

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		*handle = i2cOpen(IIC_BUS, MPU6050_ADDRESS, 0);  //sudo i2cdetect -y 1 to check addr
	}

		if (*handle < 0) {
			std::cout << "I2C is not enabled!" << std::endl;
			gpioTerminate();
			*needToExit = true;
			return;
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

	// Enable interrupt.
	char enableInt[2] = { 0x38, 0x01 };

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(*handle, enableInt, sizeof(enableInt)) != 0) {
			std::cout << "Can't enable interrupt!!" << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}

	char setDLPF[2] = {0x1A, 0x03};

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteDevice(*handle, setDLPF, sizeof(setDLPF)) != 0) {
			std::cout << "Can't set LPF." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			*needToExit = true;
			return;
		}
	}

	setRangeOfAcce(handle_MPU6050, needToExit);
	if (*needToExit) { return; }
	else { std::cout << "Scale range of accelerometer: +-2g." << std::endl; }

	// set full scale range of Gyroscope to +- 2000 °/s
	setRangeOfGyro(handle_MPU6050, needToExit);
	if (*needToExit) { return; }
	else { std::cout << "Scale range of gyroscope: +- 2000°/s." << std::endl; }
	/*	i2cWriteByteData(*handle, 0x38, 0x01);
		i2cWriteByteData(*handle, 0x37, 0x80);*/
	
}

// Magnet sensor initialization

void initializeMag(int* handle, bool* needToExit) {

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

void initializeMPUISR(bool* needToExit) {

	//if (gpioInitialise() < 0) {
	//	std::cerr << "GPIO initialization failed." << std::endl;
	//	*needToExit = true;
	//	return;
	//}

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

	char  dataGyro[2] = {0x1B, 0x18};

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

void MPU6050ReadData(int* handle, char* data) {

	char startAddr = 0x3B;
	int dataSize = 14;
	
	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		
		if (i2cWriteByte(*handle, startAddr) != 0) {
			if(i2cWriteByte(*handle, startAddr)!= 0) {
				std::cout << "Can't get data of accelerometer." << std::endl;
				i2cClose(*handle);
				gpioTerminate();
			}
		}

		if (i2cReadDevice(*handle, data, dataSize) <= 0) {
			std::cout << "Can't read data from accelerometer" << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			//return;
		}
	}
}

// Read data from Magnet sensor

void magReadData(int* handle, char* data) {
	char magAddr = 0x00;
	int dataSize = 6;

	{
		std::lock_guard<std::mutex> lock(i2cmtx);
		if (i2cWriteByte(*handle, magAddr) != 0) {
			std::cout << "Can't write address to magnet sensor." << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			return;
		}

		if (i2cReadDevice(*handle, data, dataSize) <= 0) {
			std::cout << "Can't read data from magnet sensor" << std::endl;
			i2cClose(*handle);
			gpioTerminate();
			return;
		}
	}
}

// Interrupt function.

void getAGMData(int GPIO, int level, unsigned int tick) {

	// std::cout << tick << std::endl;
	bool needToExit = false;

	//auto time = std::chrono::high_resolution_clock::now();
	// 0-5 acce, 6-7 temperature, 8-13 gyro.
	char MPU6050RawData[14]{};  
	MPU6050ReadData(&handle_MPU6050, &MPU6050RawData[0]);

	char magData[6]{};
	magReadData(&handle_GY_271, &magData[0]);
	// auto end = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double, std::milli> duration = end - time;
    // std::cout << "程序运行时间为：" << duration.count() << " ms" << std::endl;

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

	mpu6050Data.ax.store(ax);
	mpu6050Data.ay.store(ay);
	mpu6050Data.az.store(az);
	mpu6050Data.gx.store(gx);
	mpu6050Data.gy.store(gy);
	mpu6050Data.gz.store(gz);
	mpu6050Data.mx.store(mx);
	mpu6050Data.my.store(my);
	mpu6050Data.mz.store(mz);

	//std::cout << mpu6050Data.ax.load() << "|"<< mpu6050Data.ay.load() << "|" << mpu6050Data.az.load() << std::endl;
	
	mpu6050_newdata.store(true);
}

void MahonyAHRSupdateIMU(float q[4], float gx, float gy, float gz, float ax, float ay, float az) {
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
			integralFBx += twoKi * halfex * (1.0f / sampleFreq);	
			integralFBy += twoKi * halfey * (1.0f / sampleFreq);
			integralFBz += twoKi * halfez * (1.0f / sampleFreq);
            
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

void MahonyAHRSupdate(float q[4], float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz) {
	float recipNorm;
	float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
	float hx, hy, bx, bz;
	float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	// Use IMU algorithm if magnetometer measurement invalid (avoids NaN in magnetometer normalisation)
	if ((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
		MahonyAHRSupdateIMU(q, gx, gy, gz, ax, ay, az);
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

float invSqrt(float x) {
	float halfx = 0.5f * x;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	return y;
}
