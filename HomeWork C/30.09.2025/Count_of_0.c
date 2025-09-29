#include <stdio.h>


int main(void){

    int len, res;

    printf("enter the lenght of your array: ");
    scanf("%d", &len);

    if(len <= 0){
        printf("incorrect input");
        return 0;
    }

    int arr[len];

    for (int i = 0; i < len; ++i){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < len; ++i){
        if (arr[i] == 0){
            ++res;
        }
    }
    
    printf("%d", res);

}