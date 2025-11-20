cmake_minimum_required(VERSION 3.10)
project(Homework2 C)

set(CMAKE_C_STANDART 11)

add_executable(div div.c)

target_compile_options(div PRIVATE -Wall -Wextra)