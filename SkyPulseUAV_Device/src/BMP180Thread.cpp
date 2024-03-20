#include "BMP180.h"

void BMP180Thread::run() {

    float altitude;

    for(;;){

        altitude = BMP180Ins.getData();

        cout << "Altitude:" << altitude << endl;

        this_thread::sleep_for(milliseconds(20));

    }
}
