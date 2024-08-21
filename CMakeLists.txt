cmake_minimum_required(VERSION 3.17)
project(numbers LANGUAGES C CXX)

set(CMAKE_C_STANDARD  11)

add_executable(GaussianEliminationTests src/Gauss/GaussianElimination.c
        tests/Gauss/GaussianEliminationTests.cpp)

add_executable(NumberLogTest tests/numbers/log_test.cpp
        src/numbers/log_file_function.c src/numbers/log_pipe_function.c)

add_executable(numbers_main src/numbers/main.c)
add_executable(numbers_server src/numbers/server.c)
add_executable(numbers_finder src/numbers/finder.c)
add_executable(numbers_log src/numbers/log.c
        src/numbers/log_file_function.c
        src/numbers/log_pipe_function.c)

add_subdirectory(lib/google_test_lib)
include_directories(lib/google_test_lib/googletest/include)
include_directories(lib/google_test_lib/googlemock/include)

target_link_libraries(GaussianEliminationTests gtest gtest_main)

target_link_libraries(NumberLogTest gtest gtest_main)

enable_testing()

add_test(NumberLogTest NumberLogTest)

add_test(GaussianEliminationTests GaussianEliminationTests)