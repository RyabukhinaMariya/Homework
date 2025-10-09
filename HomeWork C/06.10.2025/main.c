#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* array, int left, int mid, int right);
int merge_sort(int* array, int* original_array, int size);

int main() {
    int array[100] = {0};
    int new_array[100];
    int count = 0;

    while (scanf("%d", &array[count])){
        ++count;
        if (count>=100){
            break;
        }
        int next_char = getchar();
        if (next_char == '\n' || next_char == EOF){
            break;
        }
    }
    
    int original_array[100];
    memcpy(original_array, array, count * sizeof(int));
    
    int moved_elements = merge_sort(array, original_array, count);
    
    return moved_elements;
}