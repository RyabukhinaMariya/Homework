#include <stdio.h>

int main(void) {
    int a, b;
    int n = 0;
    scanf("%d" "%d", &a, &b);
    while (a>=b*(n+1)) {
        n++;
    }
    int res = a-(b*n);
    if (n == 0) {
        printf("%d", 0);
    }
    else{
        printf("%d", res);
    }
    return 0;

} 
