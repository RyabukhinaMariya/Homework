cmake_minimum_required(VERSION 3.10)
project(Homework1 C)

set(CMAKE_C_STANDART 11)

add_executable(hello_world hello_world.c)

target_compile_options(hello_world PRIVATE -Wall -Wextra)