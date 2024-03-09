mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../raspberrypi.cmake ..
make

Replace your cross compile tool path in "raspberrypi.cmake".
