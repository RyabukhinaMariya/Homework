#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

OBJ* push(OBJ* top, char data){
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top){
    if (top == NULL){
        return top;
    }
    OBJ* ptr_next = top->next;
    free(top);
    return ptr_next;
}

void show(const OBJ* top){
    const OBJ* current = top;
    while(current != NULL){
        printf("%c\n", current->data);
        current = current->next;
    }
}
