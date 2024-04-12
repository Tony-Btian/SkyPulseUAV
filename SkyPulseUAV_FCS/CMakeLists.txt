cmake_minimum_required(VERSION 3.5)

project(SkyPulseUAV_FCS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Concurrent Network Sql Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Concurrent Network Sql Multimedia)
find_package(OpenCV REQUIRED)

# Try to find pigpio lib
find_library(PIGPIO_LIBRARY NAMES pigpio REQUIRED)

# Add the DRIVER and SENSOR directories to the include path.
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/DRIVER
    ${CMAKE_SOURCE_DIR}/MIDDLEWARES
    ${CMAKE_SOURCE_DIR}/TOOLS
    ${CMAKE_SOURCE_DIR}/SENSOR
    ${CMAKE_SOURCE_DIR}/ALGORITHM)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    ALGORITHM/mahonyfilter.h ALGORITHM/mahonyfilter.cpp

    DRIVER/i2c_device.h DRIVER/i2c_device.cpp
    DRIVER/esc_pwm_driver.h DRIVER/esc_pwm_driver.cpp
    DRIVER/gpiointerrupthandler.h DRIVER/gpiointerrupthandler.cpp
    DRIVER/fligthcontrol.h DRIVER/fligthcontrol.cpp
    DRIVER/videocapture.h DRIVER/videocapture.cpp

    MIDDLEWARES/tcp.h MIDDLEWARES/tcp.cpp
    MIDDLEWARES/decodetask.h MIDDLEWARES/decodetask.cpp
    MIDDLEWARES/Mediatorinterface.h MIDDLEWARES/DataHandlerFactory.h MIDDLEWARES/DataHandler.h
    MIDDLEWARES/handler_bmp180.h MIDDLEWARES/handler_bmp180.cpp
    MIDDLEWARES/concretemediator.h MIDDLEWARES/concretemediator.cpp

    SENSOR/barometer_bmp180.h SENSOR/barometer_bmp180.cpp
    SENSOR/magnetometer_gy271.h SENSOR/magnetometer_gy271.cpp
    SENSOR/gyroacelemeter_gy521.h SENSOR/gyroacelemeter_gy521.cpp
    SENSOR/sensormanager.h SENSOR/sensormanager.cpp

    TOOLS/threadpool.h TOOLS/threadpool.cpp
    TOOLS/databasemanager.h TOOLS/databasemanager.cpp
    TOOLS/observer.h
    TOOLS/observable.h TOOLS/observable.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SkyPulseUAV_FCS
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SkyPulseUAV_FCS APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SkyPulseUAV_FCS SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SkyPulseUAV_FCS
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SkyPulseUAV_FCS PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Concurrent
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Multimedia
    ${OpenCV_LIBS}
    ${PIGPIO_LIBRARY})

set_target_properties(SkyPulseUAV_FCS PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS SkyPulseUAV_FCS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SkyPulseUAV_FCS)
endif()
