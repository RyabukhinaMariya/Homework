#include <stdio.h>
#include <stdint.h>


// Функция для получения двоичного представления в дополнительном коде
void print_binary(int32_t num) {
    int bits = sizeof(num) * 8;
    
    uint32_t mask = 1U << (bits - 1);
    
    printf("  ");
    for (int i = 0; i < bits; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        
        if ((i + 1) % 8 == 0 && i != bits - 1) {
            printf(" ");
        }
        
        mask >>= 1;
    }
}

// Функция для сложения в двоичном виде столбиком
void binary_column_addition(int32_t a, int32_t b) {
    printf("\nbinary_summarize \n");
    
    print_binary(a);
    printf("   (%d)\n", a);
    
    printf("+ ");
    print_binary(b);
    printf("   (%d)\n", b);
    
    int32_t sum = a + b;
    print_binary(sum);
    printf("   (%d)\n", sum);
}

int main() {
    int32_t num1, num2;
    
    printf("print first num ");
    scanf("%d", &num1);
    
    printf("print second num ");
    scanf("%d", &num2);
    
    printf("\n bin numbers\n");
    
    printf("first num (%d): ", num1);
    print_binary(num1);
    printf("\n");
    
    printf("second num (%d): ", num2);
    print_binary(num2);
    printf("\n");
    
    binary_column_addition(num1, num2);

    int32_t sum = num1 + num2;
    
    printf("\n summs \n");
    printf("bin summ ");
    print_binary(sum);
    printf("\n");
    
    printf("dec summ %d\n", sum);
    
    return 0;
}
