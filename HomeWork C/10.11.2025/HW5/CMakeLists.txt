cmake_minimum_required(VERSION 3.10)
project(Homework5 C)

set(CMAKE_C_STANDARD 11)

add_executable(correct_string correct_string.c stack.c)
add_executable(deykstra_alg deykstra_alg.c stack.c)

target_compile_options(correct_string PRIVATE -Wall -Wextra)

target_compile_options(deykstra_alg PRIVATE -Wall -Wextra)
