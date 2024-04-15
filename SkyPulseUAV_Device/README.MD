# Code of Raspberry Pi 

To be noticed that this part of code is Cmake-based and has been merged into _SkyPulseUAV_FCS_ (QT-based) in previous folder. 

## Requirements:

- _Cmake_ 3.12 or newer.

- _ARM compile toolchain_ version depends on that of your Raspberry Pi.

## Build with the following steps:

### If you want to build from your PC (cross compiling):

- Make sure you have installed correct _compile toolchain_ on your PC, and **edit the path in _Raspberrypi.cmake_**.

- **You have to link the library first before using!**
```
    cd lib
    ln -s libsockpp.so.2 libsockpp.so
    ln -s libpigpio.so.1 libpigpio.so
    cd ../test/testLib
    ln -s libboost_unit_test_framework.so.1.74.0 libboost_unit_test_framework.so
```

- Create link with necessary libraries and compile in newly created build folder (for better isolation).
```
    mkdir ../build && cd ../build
    cmake -DCMAKE_TOOLCHAIN_FILE=../Raspberrypi.cmake ..
    make
```

### If you want to build from Raspberry Pi:

- Make sure you have already installed the following libraries:
    - Pigpio address: https://abyz.me.uk/rpi/pigpio
    - Sockpp address: https://github.com/fpagliughi/sockpp

- Check if your Cmake version meets the minimum requirement.
