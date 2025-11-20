#ifndef STACK_H
#define STACK_H

typedef struct tag_obj {
    char data;
    struct tag_obj* next;
} OBJ;

// Объявления функций стека
OBJ* push(OBJ* top, char data);
OBJ* pop(OBJ* top);
void show(const OBJ* top);

#endif
