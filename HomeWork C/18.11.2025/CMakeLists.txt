cmake_minimum_required(VERSION 3.10)
project(SortedArray)

set(CMAKE_C_STANDARD 99)

add_executable(sorted_array 
    main.c 
    array_operations.c
    tests_array.c
)

add_custom_target(test
    COMMAND sorted_array --test
    DEPENDS sorted_array
    COMMENT "Running tests"
)