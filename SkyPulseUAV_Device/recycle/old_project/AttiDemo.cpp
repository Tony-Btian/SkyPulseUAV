#include <iostream>
#include <cstring>
#include <condition_variable>

#include "AttiDataCollect.hpp"
#include "BaroDataCollect.hpp"
#include "SonicDataCollect.hpp"
#include "pigpio.h"

std::atomic<bool> initialise_ready(false);
std::atomic<bool> calibrate_ready(false);
std::atomic<bool> mpu6050_newdata(false);

std::mutex i2cmtx;
std::mutex cvmtx;
std::condition_variable cv;

MPU6050Data mpu6050Data;

int handle_MPU6050 = 0;  // IIC handles of sensors.
int handle_GY_271 = 0;
int handle_BMP180 = 0;

int main(int argc, const char* argv[]) {

	bool needToExit = false;

	int sample_rate_int = 200; // MPU6050.

	char sample_rate = (1000 / sample_rate_int) - 1; // 1000/sample_rate_int if DLPF is enabled.

	if(argc < 2 || strcmp(argv[1], "start") != 0) {
		std::cout<<"please use \"sudo ./[filename] start\" to start"<<std::endl;
		return 1;
	}

	// Initialize data of MPU6050.
	initializeMPU6050Data(mpu6050Data); 

	if (gpioInitialise() < 0) {
		std::cout << "pigpio is not ready!" << std::endl;
		return 1;
	}

	initializeMPU(&handle_MPU6050, &sample_rate, &needToExit);
	if (needToExit) { return 1; }
	else { std::cout << "Initialization of MPU6050 successfully." << std::endl; }

	initializeMag(&handle_GY_271, &needToExit);
	if (needToExit) { return 1; }
	else { std::cout << "Initialization of GY271 successfully." << std::endl; }

	initializeBaro(&handle_BMP180, &needToExit);
	if (needToExit) { return 1; }
	else { std::cout << "Initialization of BMP180 successfully." << std::endl; }

	//SensorData sensorData = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	AttitudeData attitudeData = { 0.0f, 0.0f, 0.0f };
	//BaroData baroData = { 0.0f, 0.0f, 0.0f };

	DataCollectionThread dataCollection(attitudeData);
	//AttiFilterThread MahonyFilter(attitudeData);
	BaroDataCollectionThread baroDataCollection;
	UltraSonicCollectionThread ultraSonicCollection;


	dataCollection.start();
	//MahonyFilter.start();
	ultraSonicCollection.start();
	//baroDataCollection.start();

	/********************************************************************************
	Interfaces: 
	20hz  (atom)float distance - Distance from drone to the nearest obstacle (cm).
	200hz float attitudeData.roll - Roll angle (°).
	      float attitudeData.pitch - Pitch angle (°).
	      float attitudeData.yaw - Yaw angle (°).
	100hz  (atom)float altitude - Absolute altitude of drone (m).
	*********************************************************************************/

	dataCollection.join();
	//MahonyFilter.join();
	ultraSonicCollection.join();
	//baroDataCollection.join();

	return 0;
}
		
	
	
