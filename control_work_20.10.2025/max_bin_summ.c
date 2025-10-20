#include <stdio.h>
#include <stdlib.h>


int bin_sum (int n){
    int s = 0;
    while (n){
        s += n % 2;
        n /= 2;
    }

    return s;
}


int main(){
    int len = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int sum_arr[5];
    int max_sum = 0;

    for (int i = 0; i < len; ++i){
        sum_arr[i] = bin_sum(arr[i]);
        max_sum = sum_arr[i] > max_sum ? sum_arr[i] : max_sum;
    }

    for (int i = 0; i < len; ++i){
        if (sum_arr[i] == max_sum){
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
