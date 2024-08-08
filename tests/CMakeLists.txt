cmake_minimum_required(VERSION 3.22)

project(circularBuffer_test)

add_executable(${PROJECT_NAME} CircularBuffer_test.cpp)

enable_testing()
find_package(GTest REQUIRED)

target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main)

target_include_directories(${PROJECT_NAME} PRIVATE 
GTEST_INCLUDE_DIRS
${CMAKE_SOURCE_DIR}/src/
)
gtest_discover_tests(${PROJECT_NAME})

## code coverage
set(CMAKE_CXX_FLAGS "-g -O0 -ftest-coverage -fprofile-arcs")

add_custom_target(coverage 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E
    rm -rf report && mkdir report && gcovr -r "${CMAKE_SOURCE_DIR}" --html --html-details -o coverage.html
)