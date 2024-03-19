cmake_minimum_required(VERSION 3.12)
project(attitude)

set(CMAKE_CXX_STANDARD 17)

# find_package(sockpp REQUIRED)
aux_source_directory(${PROJECT_SOURCE_DIR}/src CFILE)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# add_library(my_library STATIC ${CFILE})
add_executable(${PROJECT_NAME} ${CFILE} main.cpp )

target_link_libraries(${PROJECT_NAME} pigpio pthread sockpp)

#
