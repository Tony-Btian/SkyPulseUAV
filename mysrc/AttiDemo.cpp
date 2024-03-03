#include <iostream>
#include <cstring>
#include <condition_variable>

#include "AttiDataCollect.hpp"
#include "AttiFilter.hpp"
#include "BaroDataCollect.hpp"

std::atomic<bool> initialise_ready(false);
std::atomic<bool> calibrate_ready(false);
std::atomic<bool> mpu6050_newdata(false);

std::mutex i2cmtx;
std::mutex cvmtx;
std::condition_variable cv;

MPU6050Data mpu6050Data;

int handle_MPU6050 = 0;  // IIC handles of sensor.
int handle_GY_271 = 0;

int main(int argc, const char* argv[]) {

	if(argc < 2 || strcmp(argv[1], "start") != 0) {
		std::cout<<"please use \"sudo ./[filename] start\" to start"<<std::endl;
		return 1;
	}

	// Initialize data of MPU6050.
	initializeMPU6050Data(mpu6050Data); 
	
	//SensorData sensorData = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	AttitudeData attitudeData = { 0.0f, 0.0f, 0.0f };
	BaroData baroData = { 0.0f, 0.0f, 0.0f };

	DataCollectionThread dataCollection;
	AttiFilterThread MahonyFilter(attitudeData);
	BaroDataCollectionThread baroDataCollection(baroData);

	dataCollection.start();
	MahonyFilter.start();
	//baroDataCollection.start();

	dataCollection.join();
	MahonyFilter.join();
	//baroDataCollection.join();

	return 0;
}
		
	
	
