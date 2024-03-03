#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <atomic>

#include "MahonyAHRS.h"
#include "AttiFilter.hpp"

extern MPU6050Data mpu6050Data;

void AttiFilterThread::run() {

	int offset_count = 0;  // counter for initialization of sensor

	float ax_offset = 0, ay_offset = 0, az_offset = 0, gx_offset = 0, gy_offset = 0, gz_offset = 0; // offset sum of gyroscale and accelerometer;
	float mx_offset = 0, my_offset = 0, mz_offset = 0;
	float ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0, roll = 0, pitch = 0, yaw = 0;
	float mx = 0, my = 0, mz = 0;
	bool ready = false;

	//int sample_rate = 500;
	int time = 0;

	// std::this_thread::sleep_for(std::chrono::microseconds(static_cast<long long>(500000)));
	// std::cout << "Now the MPU6050 and GY271 are doing calibration. Please wait..." << std::endl;

	while (1) {

		std::unique_lock<std::mutex> lock(cvmtx);
		cv.wait(lock, [] {return mpu6050_newdata.load() == true; });

		// if (mpu6050_newdata.load()) {
			
		ax = mpu6050Data.ax.load();
		ay = mpu6050Data.ay.load();
		az = mpu6050Data.az.load();
		gx = mpu6050Data.gx.load();
		gy = mpu6050Data.gy.load();
		gz = mpu6050Data.gz.load();
		mx = mpu6050Data.mx.load();
		my = mpu6050Data.my.load();
		mz = mpu6050Data.mz.load();

		if (!ready) {
			gx_offset += gx;
			gy_offset += gy;
			gz_offset += gz;

			ax_offset += ax;
			ay_offset += ay;
			az_offset += az;

			mx_offset += mx;
			my_offset += my;
			mz_offset += mz;

			offset_count++;

			if (offset_count > 3000)
			{
				gx_offset = gx_offset / offset_count;
				gy_offset = gy_offset / offset_count;
				gz_offset = gz_offset / offset_count;

				ax_offset = ax_offset / offset_count;
				ay_offset = ay_offset / offset_count;
				az_offset = az_offset / offset_count;

				mx_offset = mx_offset / offset_count;
				my_offset = my_offset / offset_count;
				mz_offset = mz_offset / offset_count;
				// az_offset -= 9.81f; // 去除重力加速度常量

				offset_count = 0;

				calibrate_ready.store(true);
				ready = true;
			}
		}

		else {
			gx -= gx_offset;
			gy -= gy_offset;
			gz -= gz_offset;

			ax -= ax_offset;
			ay -= ay_offset;
			az -= az_offset;

			mx -= mx_offset;
			my -= my_offset;
			mz -= mz_offset;

			MahonyAHRSupdate(gx, gy, gz, ax, ay, az, mx, my, mz);

			{
				std::unique_lock<std::shared_mutex> lock(sharedAtti.attitude_mutex);
				sharedAtti.roll = atan2(2.0f * (q0 * q1 + q2 * q3), q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3) * RAD_TO_DEG;
				sharedAtti.pitch = asin(2.0f * (q0 * q2 - q3 * q1)) * RAD_TO_DEG;
				sharedAtti.yaw = atan2(2.0f * (q0 * q3 + q1 * q2), q0 * q0 + q1 * q1 - q2 * q2 + q3 * q3) * RAD_TO_DEG;

				roll = sharedAtti.roll;
				pitch = sharedAtti.pitch;
				yaw = sharedAtti.yaw;
			}
		}

		if (time > 5000) {
			std::cout << roll << "|" << pitch << "|" << yaw << std::endl;
		}
		else if (time == 5000) {
			std::cout << "Calibration successfully! Ready to output attitude information." << std::endl;
			std::this_thread::sleep_for(std::chrono::microseconds(static_cast<long long>(10000)));
			time++;
		}
		else {
			time++;
		}

		//mpu6050_newdata.store(false);
		// }
	}
	return;
}
