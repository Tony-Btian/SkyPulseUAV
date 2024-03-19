#include <pigpio.h>
#include <iostream>
#include <unistd.h>

#include "UART.h"


UART::UART (uint32_t baudRate) {

    const char* device = "/dev/ttyAMA0";
    handle = serOpen(const_cast<char*>(device), baudRate , 0);
    if (handle < 0) {
        std::cerr << "Unable to open UART\n";
    }

    char data[] = "Initialization of UART done.";
    unsigned int data_len = sizeof(data) - 1;

    writeUART(data, data_len);
}

UART::~UART() {

    if (serClose(handle) != 0) {
        std::cerr << "Unable to close UART\n";
    }

}

void UART::writeUART(char* buf, unsigned int size) {

    if(serWrite(handle, buf, size) != 0) {
        std::cerr << "Unable to write UART\n";
    }
}

void UART::readUART() {


}

