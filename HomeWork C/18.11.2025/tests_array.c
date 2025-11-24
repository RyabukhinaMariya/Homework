#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "array_operations.h"

// Функция для сравнения массивов
void assert_arrays_equal(float* actual, float* expected, int size, const char* test_name) {
    printf("---Test: %s---\n", test_name);
    
    for (int i = 0; i < size; i++) {
        if (actual[i] != expected[i]) {
            printf("Fail at index %d expected %f, got %f, test %c\n\n", 
                   i, expected[i], actual[i], test_name);
            assert(0);
        }
    }
    printf("Test %s passed\n\n", test_name);
}

void test_make_new_arr() {
    printf("---Test: make_new_arr---\n");
    
    int curr_size = 3;
    float* arr = (float*)malloc(curr_size * sizeof(float));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    float* new_arr = make_new_arr(arr, curr_size);
    
    assert(new_arr != NULL);
    assert(new_arr[0] == 1);
    assert(new_arr[1] == 2);
    assert(new_arr[2] == 3);
    
    printf("Test make_new_arr passed\n\n");

    free(new_arr);
}


void test_add() {
    
    int count_of_el = 3;
    int max_count = 10;
    float* array = (float*)malloc(max_count * sizeof(float));
    
    array[0] = 2.5;
    array[1] = 4.0;
    array[2] = 6;
    
    add(array, count_of_el, 1);
    count_of_el++;

    add(array, count_of_el, 3);
    count_of_el++;
    
    add(array, count_of_el, 7.9);
    count_of_el++;
    
    float expected[] = {1, 2.5, 3, 4.0, 6, 7.9};
    assert_arrays_equal(array, expected, count_of_el, "Add");
    
    free(array);
}

void test_add_duplicates() {
    
    int count_of_el = 3;
    int max_count = 10;
    float* array = (float*)malloc(max_count * sizeof(float));
    
    array[0] = -3;
    array[1] = 1.8;
    array[2] = 5;
    
    add(array, count_of_el, -3);
    count_of_el++;
    
    add(array, count_of_el, 1.8);
    count_of_el++;
    
    float expected[] = {-3, -3, 1.8, 1.8, 5};
    assert_arrays_equal(array, expected, count_of_el, "Add duplicates");
    
    free(array);
}

void run_all_tests() {
    
    test_make_new_arr();
    test_add();
    test_add_duplicates();


    printf("All tests passed\n");
}
