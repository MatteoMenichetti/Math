cmake_minimum_required(VERSION 3.26)
project(numbers C)

set(CMAKE_C_STANDARD 11)

add_executable(main src/main.c)

add_executable(server src/server.c)

add_executable(finder src/finder.c)
