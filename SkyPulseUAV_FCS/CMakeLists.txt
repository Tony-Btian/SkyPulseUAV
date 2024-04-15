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
    ${CMAKE_SOURCE_DIR}/COMM
    ${CMAKE_SOURCE_DIR}/DRIVER
    ${CMAKE_SOURCE_DIR}/SENSOR
    ${CMAKE_SOURCE_DIR}/SYSTEM
    ${CMAKE_SOURCE_DIR}/MIDDLEWARES)


set(PROJECT_SOURCES
    main.cpp

    COMM/tcp.h COMM/tcp.cpp

    DRIVER/i2cdriver.h DRIVER/i2cdriver.cpp
    DRIVER/motorpwm.h DRIVER/motorpwm.cpp

    SENSOR/mpu6050.h SENSOR/mpu6050.cpp
    SENSOR/bmp180.h SENSOR/bmp180.cpp
    SENSOR/gy271.h SENSOR/gy271.cpp

    SYSTEM/mainsystem.h SYSTEM/mainsystem.cpp
    SYSTEM/sensormanager.h SYSTEM/sensormanager.cpp

    MIDDLEWARES/MediatorInterface.h
    MIDDLEWARES/concretemediator.h MIDDLEWARES/concretemediator.cpp
    MIDDLEWARES/observable.h MIDDLEWARES/observable.cpp
    MIDDLEWARES/Observer.h
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
