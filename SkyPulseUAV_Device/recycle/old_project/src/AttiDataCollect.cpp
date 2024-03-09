#include <iostream>
#include <thread>
#include <pigpio.h>
#include <unistd.h>
#include <cmath>
#include <chrono>

#include "AttiDataCollect.hpp"
#include "MahonyAHRS.h"

extern MPU6050Data mpu6050Data;

void DataCollectionThread::run() {

	bool needToExit = false;  // flag of error.

	int offset_count = 0;  // counter for initialization of sensor

	// offset sum of gyroscale and accelerometer;
	// float a_offset[3] = {502.853f, -517.508f, 17268.6f};
	// float g_offset[3] = {1593.1f, 425.247f, 92.1504f};
	// float m_offset[3] = {24516.9f, 21674.9f, -26668.1f}; 

	float a_offset[3] = {0}, g_offset[3] = {0}, m_offset[3] = {0};
	float q[4] = {1.0f, 0.0f, 0.0f, 0.0f};

	// Initialization of 
	float a[3] = {0}, g[3] = {0}, m[3] = {0}, roll = 0, pitch = 0, yaw = 0;

	bool ready = false;

	uint32_t time = 0;

	initializeMPUISR(&needToExit);
	if (needToExit) { return; }
	else { std::cout << "Initialization of MPU6050 interrupt successfully." << std::endl; }

	for(;;) {
		// std::cout << mpu6050Data.ax.load() << mpu6050_newdata.load() << std::endl;
		if(mpu6050_newdata.load()) {

			mpu6050_newdata.store(false);

			a[0] = mpu6050Data.ax.load();
			a[1] = mpu6050Data.ay.load();
			a[2] = mpu6050Data.az.load();
			g[0] = mpu6050Data.gx.load();
			g[1] = mpu6050Data.gy.load();
			g[2] = mpu6050Data.gz.load();
			m[0] = mpu6050Data.mx.load();
			m[1] = mpu6050Data.my.load();
			m[2] = mpu6050Data.mz.load();

			if (!ready) {
				g_offset[0] += g[0];
				g_offset[1] += g[1];
				g_offset[2] += g[2];

				a_offset[0] += a[0];
				a_offset[1] += a[1];
				a_offset[2] += a[2];

				m_offset[0] += m[0];
				m_offset[1] += m[1];
				m_offset[2] += m[2];

				offset_count++;

				if (offset_count > 8000)
				{
					g_offset[0] = g_offset[0] / offset_count;
					g_offset[1] = g_offset[1] / offset_count;
					g_offset[2] = g_offset[2] / offset_count;

					a_offset[0] = a_offset[0] / offset_count;
					a_offset[1] = a_offset[1] / offset_count;
					a_offset[2] = a_offset[2] / offset_count;

					m_offset[0] = m_offset[0] / offset_count;
					m_offset[1] = m_offset[1] / offset_count;
					m_offset[2] = m_offset[2] / offset_count;
					// a_offset[2] -= 9.81f; // 去除重力加速度常量

					offset_count = 0;

					//calibrate_ready.store(true);
					ready = true;
				}
			}
			// std::cout << "*********************************************" << std::endl;
			// std::cout << g_offset[0] << "," << g_offset[1] << "," <<g_offset[2] << std::endl;
			// std::cout << a_offset[0] << "," <<a_offset[1] << "," <<a_offset[2] << std::endl;
			// std::cout << m_offset[0] << "," <<m_offset[1] << "," <<m_offset[2] << std::endl;
			// std::cout << "*********************************************" << std::endl;

			else {
				g[0] = (g[0] - g_offset[0]) / (16.384f) * DEG_TO_RAD;
				g[1] = (g[1] - g_offset[1]) / (16.384f) * DEG_TO_RAD;
				g[2] = (g[2] - g_offset[2]) / (16.384f) * DEG_TO_RAD;

				a[0] = ((a[0] - a_offset[0]) / 16384.0f)*9.818f;
				a[1] = ((a[1] - a_offset[1]) / 16384.0f)*9.818f;
				a[2] = ((a[2] - a_offset[2]) / 16384.0f)*9.818f;
				a[2] = a[2] + 9.818f;

				m[0] -= m_offset[0];
				m[1] -= m_offset[1];
				m[2] -= m_offset[2];

				m[0] = m[0] * 0.000122f;
				m[1] = m[1] * 0.000122f;
				m[2] = m[2] * 0.000122f;

				MahonyAHRSupdateIMU(q, g[0], g[1],g[2], a[0], a[1], a[2]);

				// {
				// 	std::unique_lock<std::shared_mutex> lock(sharedAtti.attitude_mutex);
				sharedAtti.roll = atan2f( (q[2]*q[3] + q[1]*q[0]) , ( 0.5f - (q[1]*q[1] + q[2]*q[2]) )) * 57.29578f;
				sharedAtti.pitch = asinf((q[1]*q[3] - q[2]*q[0])) * 57.29578f;
				sharedAtti.yaw = atan2f( (q[1]*q[2] + q[3]*q[0]), ( 0.5f - (q[2]*q[2] + q[3]*q[3]) ) ) * 57.29578f;
				if (sharedAtti.yaw < 0) sharedAtti.yaw += 360;

				roll = sharedAtti.roll;
				pitch = sharedAtti.pitch;
				yaw = sharedAtti.yaw;
				// }
				std::cout << roll << "|" << pitch << "|" << yaw << std::endl;	
				//std::cout << roll << "|" << pitch  << std::endl;
			}
			

			
		}
	}

	return; 
}

// Accelerometer and gyroscope

//char acceData[6]{};	
//acceReadData(handle_MPU6050, &acceData[0], &needToExit);

//char gyroData[6]{};
//gyroReadData(handle_MPU6050, &gyroData[0], &needToExit);

//char magData[6]{};
//magReadData(handle_GY_271, &magData[0], &needToExit);

//short ax, ay, az, gx, gy, gz, mx, my, mz;

//ax = ((acceData[0] << 8) | acceData[1]);
//ay = ((acceData[2] << 8) | acceData[3]);
//az = ((acceData[4] << 8) | acceData[5]);
//gx = ((gyroData[0] << 8) | gyroData[1]);
//gy = ((gyroData[2] << 8) | gyroData[3]);
//gz = ((gyroData[4] << 8) | gyroData[5]);
//mx = ((magData[0] << 8) | magData[1]);
//my = ((magData[2] << 8) | magData[3]);
//mz = ((magData[4] << 8) | magData[5]);

//{
//	std::unique_lock<std::shared_mutex> lock(sharedData.rawdata_mutex);
//	// divide by 16384 so that the output is x times g.

//	sharedData.accX = ax / 16384.0f;
//	sharedData.accY = ay / 16384.0f;
//	sharedData.accZ = az / 16384.0f;
//	sharedData.gyroX = gx / 16.4f;
//	sharedData.gyroY = gy / 16.4f;
//	sharedData.gyroZ = gz / 16.4f;

//	// lack of pre-processing of data from magnet sensor
//	sharedData.magX = mx;  
//	sharedData.magY = my;
//	sharedData.magZ = mz;

//	/*ready = sharedData.calibrate_ready;*/
//}

//if (calibrate_ready.load()) {
//	std::cout << mx << " |" << my << " |" << mz << std::endl;
//}

//std::cout << "x_acc:" << sharedData.accX << " y_acc:" << sharedData.accY << " z_acc:" << sharedData.accZ << std::endl;

//std::cout << "--------------------------------------------------------" << std::endl;

//next_sample_time += std::chrono::microseconds((long long)( (1.0 / sample_rate_int)* 1000000));

//std::this_thread::sleep_for(std::chrono::microseconds(static_cast<long long>(1e6 / sample_rate_int)));

	
	
	

	
	
	
