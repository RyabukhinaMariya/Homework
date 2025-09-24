#include <stdio.h>

int main(void){
    int comb[28] = {0};
    int res = 0;
    for (int i = 0; i <= 9; ++i){
        for (int j = 0; j <= 9; ++j){
            for (int k = 0; k <= 9; ++k){
                ++comb[i+j+k];
            }
        }
    }
    for (int i = 0; i <= 27; ++i){
        res = res + comb[i]*comb[i];
    }
    printf("%d", res);
    return 0;
}