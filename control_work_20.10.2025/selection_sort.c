#include <stdio.h>
#include <stdlib.h>


void selection_sort( int* arr, int len){
    int pos_of_min = 0;
    for (int i = 0; i < len; ++i){
        pos_of_min = i;
        for (int j = i; j < len; ++j){
            if (arr[pos_of_min] > arr[j]){
                pos_of_min = j;
            }
        }
        if (i != pos_of_min){
            arr[i] += arr[pos_of_min];
            arr[pos_of_min] = arr[i] - arr[pos_of_min];
            arr[i] -= arr[pos_of_min];
        }
    }
}

int main(){
    int len = 7;
    int arr[7] = {1, 4, 3, 2, 5, 7, 3};

    selection_sort(arr, len);

    for (int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}
