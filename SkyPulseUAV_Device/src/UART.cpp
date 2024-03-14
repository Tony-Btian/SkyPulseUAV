#include <pigpio.h>

#include "UART.h"

UART::UART (uint16_t baudRate) {

    handle = serOpen("/dev/ttyS0", baudRate , 0);

}

UART::~UART() {

    serClose(handle);

}

int UART::serialInit() {


}