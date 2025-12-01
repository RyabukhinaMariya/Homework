#include <stdio.h>
#include <stdlib.h>
int f(int* a, int* b, int len_a, int len_b){
    if (len_a != len_b){
        return len_a > len_b ? 0:1;
    }
    for (int i = 0; i < len_a && i < len_b; ++i){
        if (a[i] != b[i]){
        return a[i] > b[i] ? 0:1;
        }
    }
    return 2;
}
int main(){

    int first_num[] = {0, 0, 1};
    int second_num[3] = {0, 1, 0};
    
    int res = f(first_num, second_num, 3, 3);

    if (res == 0){
        printf("First number is bigger");
    }
    if (res == 1){
        printf("Second number is bigger");
    }
    if (res == 2){
        printf("Numbers are equal");
    }

    return 0;
}
