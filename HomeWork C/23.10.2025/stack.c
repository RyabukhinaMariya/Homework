#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tag_obg {
    char data;
    struct tag_obg* next; //указывает на топ стека
} OBJ;


OBJ* push(OBJ* top, char data){
    OBJ* ptr = malloc(sizeof(OBJ)); //создаем указатель на новую выделяемую память
    ptr -> data = data; //передаем новое значение в стек
    ptr -> next = top; //некст снова указывает на топ стека
    return ptr;
}


OBJ* pop(OBJ* top){
    if (top == NULL){
        return top; //если стек пуст, ничего не предпринимаем
    }

    OBJ* ptr_next = top -> next; // есть объект и указатель некст на него, 
    free(top);

    return ptr_next;
}


void show(const OBJ* top){
    const OBJ* current = top;
    while(current != NULL){
        printf("%c\n", current -> data);
        current = current -> next;
    }
}


int main(void){
    OBJ* top = NULL;

    return 0;
}
