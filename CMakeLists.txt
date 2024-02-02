cmake_minimum_required(VERSION 3.17)
project(numbers LANGUAGES C CXX)

set(CMAKE_C_STANDARD  11)

add_executable(LogTest tests/log_test.cpp
        src/log_file_function.c)

add_executable(main src/main.c)
add_executable(server src/server.c)
add_executable(finder src/finder.c)
add_executable(log src/log.c
        src/log_file_function.c
        src/log_pipe_function.c)

add_subdirectory(lib/google_test_lib)
include_directories(lib/google_test_lib/googletest/include)
include_directories(lib/google_test_lib/googlemock/include)

target_link_libraries(LogTest gtest gtest_main)

enable_testing()

add_test(LogTest LogTest)