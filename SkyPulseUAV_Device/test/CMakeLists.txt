aux_source_directory(${PROJECT_SOURCE_DIR}/src CFILE)

include_directories(/usr/include)
include_directories(/usr/local/include)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/test/testLib)
link_directories(${PROJECT_SOURCE_DIR}/lib)


add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (Test ${CFILE} test.cpp)

target_link_libraries(
    Test ${CMAKE_CURRENT_SOURCE_DIR}/testLib/libboost_unit_test_framework.so pigpio sockpp
)

add_test (NAME MyTest COMMAND Test)