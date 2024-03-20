#include <iostream>

#include "MahonyFilter.h"
#include "MPU6050.h"

using namespace std;

void MahonyFilterThread::run() {

    // Register callback function, when MPU6050 getData() called, data will be passed to filter.
    MPU6050Ins.setCallback([this](float a[3], float g[3], float m[3]) {

        MahonyFilterIns.readRawData(a, g, m);
        
    });

    for(;;) {

        if(MahonyFilterIns.isDataReady()) {

            MahonyFilterIns.MahonyAHRSupdate();

            auto angles = MahonyFilterIns.getAngleTest();

        }   

    }

}