
include_directories(/usr/include)
include_directories(/usr/local/include)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/test/testLib)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (Test test.cpp)
target_link_libraries(
    Test ${CMAKE_CURRENT_SOURCE_DIR}/testLib/libboost_unit_test_framework.so
)

add_test (NAME MyTest COMMAND Test)