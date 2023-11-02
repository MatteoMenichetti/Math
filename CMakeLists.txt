cmake_minimum_required(VERSION 3.17)
project(numbers)

set(CMAKE_CXX_STANDARD 11)

add_executable(AllTest tests/test.cpp tests/main.cpp src/function.c)

add_executable(numbers src/main.c)
add_executable(server src/server.c)
add_executable(finder src/finder.c)

add_subdirectory(lib/google_test_lib)
include_directories(lib/google_test_lib/googletest/include)
include_directories(lib/google_test_lib/googlemock/include)

target_link_libraries(AllTest gtest gtest_main)
