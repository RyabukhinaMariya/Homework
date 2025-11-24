#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_operations.h"
#include "tests_array.h" 

#define END 0
#define ADD 1
#define DELETE 2
#define PRINT_ARRAY 3

void print_options() {
    printf("---Sorted Array Operations---\n");
    printf("0 - Exit\n");
    printf("1 - Add element\n");
    printf("2 - Remove last element\n");
    printf("3 - Print array\n");
}

int main(int argc, char* argv[]){
    // Обработка аргументов командной строки
    if (argc == 2) {
        if (strcmp(argv[1], "--test") == 0) {
            run_all_tests();  // Теперь эта функция видна!
            return 0;
        }
    }
    
    // Интерактивный режим
    int count_of_el = 0, max_count = 2;
    float *array = (float*)malloc(max_count * sizeof(float));
    int op;
    float x;
    
    while (1){
        print_options();
        if (scanf("%d", &op)  != 1 || op < 0 || op > 3){
            printf("Invalid operation\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (op){
            case ADD:
                if (count_of_el >= max_count) {
                    float *new_arr = make_new_arr(array, max_count);
                    if (new_arr != NULL){
                        array = new_arr;
                        max_count *= 2;
                    }
                    else{
                        printf("Cannot make new array\n");
                        break;
                    }
                }
                printf("Enter element to add: ");
                if (scanf("%f", &x) != 1) {
                    printf("Invalid input\n");
                    while (getchar() != '\n');
                    break;
                }
                add(array, count_of_el, x);
                ++count_of_el;
                break;
                
            case DELETE:
                if (count_of_el > 0){
                    --count_of_el;
                }
                else{
                    printf("Array is already empty\n");
                }
                break;
                
            case PRINT_ARRAY:
                print_arr(array, count_of_el);
                break;
                
            case END:
                free(array);
                return 0;
                
            default:
                printf("Invalid operation\n");
                break;
        }
    }

    free(array);
    return 0;
}