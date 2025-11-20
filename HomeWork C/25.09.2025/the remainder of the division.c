#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b;
    int n = 0;

    scanf("%d %d", &a, &b);

    int a1 = abs(a);
    int b1 = abs(b);
    int sign = 1;

    if ((a != a1 && b == b1) || (a == a1 &&  b != b1)) sign = -1;

    if (b == 0){
        printf("incorrect input\n");
        return 0;
    }
    
    while (a1 >= b1*(n + 1)) n++;

    n*=sign;

    printf("%d\n", n);

    return 0;
}
