#include <stdio.h>

// преобразование битового массива в целое число
int bits_to_int(int arr[], int n) {
    unsigned int result = 0;
    for (int i = 0; i < n; i++) {
        result = (result << 1) | (arr[i] ? 1 : 0);
    }
    return result;
}

// выполнение циклического сдвига влево
void move_list(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

int max_num(int arr[], int n) {
    int max_val = bits_to_int(arr, n);
    
    // создание копии массива для циклических сдвигов
    int current_arr[32];
    for (int i = 0; i < n; i++) {
        current_arr[i] = arr[i];
    }
    
    // проверка циклических сдвигов
    for (int shift = 1; shift < n; shift++) {
        move_list(current_arr, n);
        int current_val = bits_to_int(current_arr, n);
        
        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    
    return max_val;
}
