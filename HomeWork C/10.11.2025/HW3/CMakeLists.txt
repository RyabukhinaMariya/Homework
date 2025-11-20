cmake_minimum_required(VERSION 3.10)
project(Homework3 C)

set(CMAKE_C_STANDART 11)

add_executable(count_0 count_0.c)
add_executable(count_occ count_occ.c)
add_executable(correct_string correct_string.c)

target_compile_options(count_0 PRIVATE -Wall -Wextra)
target_compile_options(count_occ PRIVATE -Wall -Wextra)
target_compile_options(correct_string PRIVATE -Wall -Wextra)