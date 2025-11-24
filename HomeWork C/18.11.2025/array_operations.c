#include <stdio.h>
#include <stdlib.h>
#include "array_operations.h"

float* make_new_arr(float* arr, int curr_size){ //закончилось место - создаем массив в 2 раза больше
    int new_size = curr_size * 2;
    float* new_arr = (float*)malloc(new_size * sizeof(float));

    for (int i = 0; i < curr_size; ++i){
        new_arr[i] = arr[i];
    }

    free(arr);

    return new_arr;
}

void print_arr(float* arr, int size_of_arr){
    if (size_of_arr == 0){
        printf("Array is empty");
        return;
    }
    printf("Your array is: ");
    for (int i = 0; i < size_of_arr; ++i){
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void add(float* array, int count_of_el, float el){ //добавление элемента без нарушения сортированности
    if (count_of_el == 0){
        array[0] = el;
    }
    else{
        int i = count_of_el - 1;
        while (i >= 0 && array[i] > el) {
        array[i + 1] = array[i];
        i--;
        }
        array[i+1] = el;
    }
}