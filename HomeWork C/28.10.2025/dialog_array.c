#include <stdio.h>
#include <stdlib.h>

#define END 0
#define ADD 1
#define DELETE 2
#define PRINT_ARRAY 3

void show_op(){
    printf("--Available commands--\n 0 - Exit\n 1 - Add\n 2 - Remove\n 3 - Show array\n");
}

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


int main(){
    int count_of_el = 0, max_count = 2;
    float *array = (float*)malloc(max_count * sizeof(float));
    int op;
    float x;
    
    while (1){
        show_op();
        if (scanf("%d", &op)  != 1 || op < 0 || op > 3){
            printf("Invalid operation\n");
            while (getchar() != '\n');
        }
        switch (op){
            case ADD:
            printf("Enter value you want to add: ");
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
                break;
        }

    }

    free(array);

    return 0;
}
