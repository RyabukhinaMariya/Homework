#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 15;
    int arr[2] = {1, 1};
    int len_of_str = 2;
    int curr_num = 0;

    while (len_of_str < n){
        arr[1] += arr[0];
        arr[0] = arr[1] - arr[0];
        curr_num = arr[1];

        while(curr_num){
            ++len_of_str;
            curr_num /= 10;
        }
    }

    for (int i = 0; i < len_of_str - n; ++i){
        arr[1] /= 10;
    }

    arr[1] %= 10;

    if (n < 1) printf("incorrect input");
    else if (n == 1) printf("%d", 1);
    else printf("%d\n", arr[1]);

    return 0;
}
