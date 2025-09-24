#include <stdio.h>

void reverse(int arr[], int start, int end){
    int el = 0;
    while (start < end){
        el = arr[start];
        arr[start] = arr[end];
        arr[end] = el;
        start++, end--;
    }
}

void swap(int arr[], int n, int m){
    reverse(arr, 0, n + m - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, n + m - 1);
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n + m];
    for (int i = 0; i < n + m; ++i){
        scanf("%d", &arr[i]);
    }
    swap(arr, m, n);
    for (int i = 0; i< n + m; ++i){
        printf("%d ", arr[i]);
    }
    return 0;
}