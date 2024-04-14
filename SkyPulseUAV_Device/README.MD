# Code of Raspberry Pi 

To be noticed that this part of code is 

## Requirements:

- _Cmake_ 3.12 or newer.

- _ARM compile toolchain_ version depends on that of your Raspberry Pi.

## Build with the following steps:

If you want to compile from your PC (cross compiling):

- Make sure you have installed correct _compile toolchain_ on your PC, and edit the path in _raspberrypi.cmake_.

- Create link with necessary libraries and compile in newly created build folder (for better isolation).
```
    cd lib
    ln -s libsockpp.so.2 libsockpp.so
    ln -s libpigpio.so.1 libpigpio.so
    mkdir ../build && cd ../build
    cmake -DCMAKE_TOOLCHAIN_FILE=../raspberrypi.cmake ..
    make
```