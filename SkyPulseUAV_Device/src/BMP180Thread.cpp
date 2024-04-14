#include "BMP180.h"

void BMP180Thread::run() {

    // Varible for debugging.
    float altitude;

    for(;;){

        // By calling getData(), callback function in other thread will be called  
        // to get altitude data.
        altitude = BMP180Ins.getData();

        cout << "Altitude:" << altitude << endl;

        this_thread::sleep_for(milliseconds(20));

    }
}
