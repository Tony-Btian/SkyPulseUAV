Build with the following steps:

cd lib
ln -s libsockpp.so.2.0.0 libsockpp.so.2
ln -s libsockpp.so.2 libsockpp.so
ln -s libpigpio.so.1 libpigpio.so
mkdir ../build && cd ../build
cmake -DCMAKE_TOOLCHAIN_FILE=../raspberrypi.cmake ..
make
