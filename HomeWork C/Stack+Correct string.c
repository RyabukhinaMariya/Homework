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


int correct(OBJ* top, char* elts, int len){
    for (int i = 0; i < len; ++i){
        if (elts[i] == '(' || elts[i] == '[' || elts[i] == '{'){ //добавляем в стек открывающиеся скобки 
            top = push(top, elts[i]);
        }
        else if (elts[i] == ')' || elts[i] == ']' || elts[i] == '}'){
            // проверяем, что стек не пуст и закрывающие скобки подходящего типа с помощью ASKII
            if (((int) elts[i] - (int) top -> data != 1 && (int) elts[i] - (int) top -> data != 2) || top == NULL ){
                return 0;
            }
            else{
                top = pop(top);// если все гуд удаляем верхний эл-т стека
            }
        }
    }
    return top == NULL; // проверяем что не осталось откр скобок
}


int main(void){
    OBJ* top = NULL;

    int len = 1000;
    char elts[len];
    fgets(elts, len, stdin);
    elts[strcspn(elts, "\n")] = '\0';//удаляем конечный эл-т строки
    len = strlen(elts);

    int res = correct(top, elts, len);
    
    if (res){
        printf("correct string");
    }
    else{
        printf("incorrect string");
    }

    return 0;
}