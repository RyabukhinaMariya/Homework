#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);
    int b = x * x;
    int res = (b + x) * (b + 1) + 1;
    printf("%d", res);
    return 0;
} 