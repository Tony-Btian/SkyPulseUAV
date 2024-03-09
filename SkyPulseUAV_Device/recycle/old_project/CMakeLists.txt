cmake_minimum_required(VERSION 3.0)
project(attitude)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(${PROJECT_SOURCE_DIR}/src CFILE)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# add_library(my_library STATIC ${CFILE})
add_executable(${PROJECT_NAME} ${CFILE} AttiDemo.cpp )

target_link_libraries(${PROJECT_NAME} pigpio pthread)

#