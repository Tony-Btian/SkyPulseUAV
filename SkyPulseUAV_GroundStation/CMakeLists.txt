cmake_minimum_required(VERSION 3.5)

project(SkyPulseUAV_GroundStation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Network Bluetooth PrintSupport Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Network Bluetooth PrintSupport Concurrent)

set(TS_FILES SkyPulseUAV_GroundStation_zh_CN.ts)

# Add the DRIVER and SENSOR directories to the include path.
include_directories(
    ${CMAKE_SOURCE_DIR}/COMM
    ${CMAKE_SOURCE_DIR}/PLOTING
    ${CMAKE_SOURCE_DIR}/SENSOR
    ${CMAKE_SOURCE_DIR}/SYSTEM
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SkyPulseUAV_GroundStation
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        SENSOR/MAG_HMC5883L.h SENSOR/MAG_HMC5883L.cpp
        COMM/UDP.h COMM/UDP.cpp
        COMM/TCP.h COMM/TCP.cpp
        COMM/Bluetooth.h COMM/Bluetooth.cpp
        PLOTING/qcustomplot.h PLOTING/qcustomplot.cpp
        PLOTING/Mahony_Plot.h PLOTING/Mahony_Plot.cpp
        SYSTEM/pooltask.h SYSTEM/pooltask.cpp
        resource.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SkyPulseUAV_GroundStation APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(SkyPulseUAV_GroundStation SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SkyPulseUAV_GroundStation
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(SkyPulseUAV_GroundStation PRIVATE
                      Qt${QT_VERSION_MAJOR}::Widgets
                      Qt${QT_VERSION_MAJOR}::Network
                      Qt${QT_VERSION_MAJOR}::Bluetooth
                      Qt${QT_VERSION_MAJOR}::PrintSupport
                      Qt${QT_VERSION_MAJOR}::Concurrent
                      )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SkyPulseUAV_GroundStation)
endif()
set_target_properties(SkyPulseUAV_GroundStation PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SkyPulseUAV_GroundStation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SkyPulseUAV_GroundStation)
endif()
