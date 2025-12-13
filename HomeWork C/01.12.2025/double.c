#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void print_double_exponential(double num) {
    uint64_t bits;
    memcpy(&bits, &num, sizeof(double));
    
    int sign = (bits >> 63) & 1;
    int64_t exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;
    
    if (exponent == 0x7FF) {
        if (mantissa == 0) {
            printf("%cINF", sign ? '-' : '+');
        } else {
            printf("NaN");
        }
        return;
    }
    
    // Проверка на ноль
    if (exponent == 0 && mantissa == 0) {
        printf("%c0*2^0", sign ? '-' : '+');
        return;
    }
    
    int64_t real_exp;
    long double real_mantissa;
    
    if (exponent == 0) {
        real_mantissa = (long double)mantissa / (1ULL << 52);  // F / 2^52
        real_exp = -1022;
    } else {
        real_mantissa = 1.0L + (long double)mantissa / (1ULL << 52);
        real_exp = exponent - 1023;
    }
    
    if (real_mantissa != 0 && real_mantissa < 1.0L) {
        while (real_mantissa < 1.0L) {
            real_mantissa *= 2.0L;
            real_exp--;
        }
    }
    

    printf("%c%.20Lg*2^%lld", 
           sign ? '-' : '+', 
           real_mantissa, 
           real_exp);
}

int main() {
    double number;
    
    printf("Enter a number: ");
    scanf("%lf", &number);
    
    printf("Result: ");
    print_double_exponential(number);
    printf("\n");
    
    return 0;
}
