cmake_minimum_required(VERSION 3.10)
project(Homework3 C)

set(CMAKE_C_STANDART 11)

add_executable(dialog_array dialog_array.c)
add_executable(killing killing.c)


target_compile_options(dialog_array PRIVATE -Wall -Wextra)
target_compile_options(killing PRIVATE -Wall -Wextra)
