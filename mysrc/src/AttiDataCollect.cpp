#include <iostream>
#include <thread>
#include <pigpio.h>
#include <unistd.h>
#include <cmath>
#include <chrono>

#include "AttiDataCollect.hpp"

extern MPU6050Data mpu6050Data;

void DataCollectionThread::run() {

	bool needToExit = false;  // flag of error.

	char sample_rate = 0x27;  // 0x0F: 200 Hz sampling rate.

	int sample_rate_int = 8000 / ((int)sample_rate + 1);
	
	initializeOfMPU(&handle_MPU6050, &sample_rate, &needToExit);
	if (needToExit) { return; }
	else { std::cout << "Initialization of MPU6050 successfully." << std::endl; }

	initializeOfMag(&handle_GY_271, &needToExit);
	if (needToExit) { return; }
	else { std::cout << "Initialization of GY271 successfully." << std::endl; }

	// set full scale range of accelerometer to +-2g
	setRangeOfAcce(handle_MPU6050, &needToExit);
	if (needToExit) { return; }
	else { std::cout << "Scale range of accelerometer: +-2g." << std::endl; }

	// set full scale range of Gyroscope to +- 2000 °/s
	setRangeOfGyro(handle_MPU6050, &needToExit);
	if (needToExit) { return; }
	else { std::cout << "Scale range of gyroscope: +- 2000°/s." << std::endl; }
	
	initializeOfGPIO(&needToExit);
	if (needToExit) return;
	else { std::cout << "Initialization of GPIO successfully." << std::endl; }

	// Initialization successfully, Mahony filter thread can start now.
	// initialise_ready.store(true);

	while(1) {
		if (mpu6050_newdata.load()) {
			cv.notify_one();
			mpu6050_newdata.store(false);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // sleep for 1 ms
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

	
	
	

	
	
	
