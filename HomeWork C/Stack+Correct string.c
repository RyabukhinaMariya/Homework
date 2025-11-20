#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int correct(OBJ* top, char* elts, int len){
    for (int i = 0; i < len; ++i){
        if (elts[i] == '(' || elts[i] == '[' || elts[i] == '{'){ //добавляем в стек открывающиеся скобки 
            top = push(top, elts[i]);
        }
        else if (elts[i] == ')' || elts[i] == ']' || elts[i] == '}'){
            // проверяем, что стек не пуст и закрывающие скобки подходящего типа с помощью ASKII
            if (elts[i] == ')' && top->data != '(') return 0;
            else if (elts[i] == ']' && top->data != '[') return 0;
            else if (elts[i] == '}' && top->data != '{') return 0;
            else top = pop(top);// если все хорошо удаляем верхний эл-т стека
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
