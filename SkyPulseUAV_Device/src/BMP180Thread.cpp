#include "BMP180.h"
#include "BMP180Thread.h"

void BMP180Thread::run() {

    BMP180 bmp180;

    float altitude;

    for(;;){

        altitude = bmp180.getData();

        std::cout << "Altitude:" << altitude << std::endl;

        std::this_thread::sleep_for(std::chrono::microseconds(static_cast < long long>(1000)));

    }
}
