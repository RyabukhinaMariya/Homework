#include <stdio.h>
#include <stdlib.h>

typedef struct Warrior{
    int position;
    struct Warrior* next;
} Warrior;


Warrior* create_warrior(int pos) {
    Warrior* new_warrior = (Warrior*)malloc(sizeof(Warrior));
    new_warrior->position = pos;
    new_warrior->next = NULL;
    return new_warrior;
}

Warrior* create_circle(int n) {
    if (n <= 0) return NULL;
    
    Warrior* first = create_warrior(1);
    Warrior* current = first;
    
    for (int i = 2; i <= n; i++) {
        current->next = create_warrior(i);
        current = current->next;
    }
    
    current->next = first; 
    return first;
}

int result(int n, int m) {
    // Создаем круг из n воинов
    Warrior* circle = create_circle(n);
    Warrior* current = circle;
    Warrior* prev = NULL;
    
    Warrior* last = circle;
    while (last->next != circle) {
        last = last->next;
    }
    
    // Пока в круге не останется один воин
    while (current->next != current) {
        for (int count = 1; count < m; count++) {
            prev = current;
            current = current->next;
        }
        
        // Удаляем текущего воина
        prev->next = current->next;
        
        if (current == circle) {
            circle = current->next;
        }
        
        free(current);
        current = prev->next;
    }
    
    int survivor = current->position;
    free(current);
    return survivor;
}

int main(){
    int n = 41;
    int m = 3;

    int res = result(n, m);

    printf("%d", res);

    return 0;
}
