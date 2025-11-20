#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int priority(char symb){//заменяем символы на их приоритетность
    switch(symb) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return 0;
    }
}


void deikstra(OBJ* top, char* inf_str, int len_str, char* post_str){
    int len_post = 0;
    for (int i = 0; i < len_str; ++i){ //проверяем не цифра ли это по ASKII
        if ((int) inf_str[i] >= 48 && (int) inf_str[i] <= 57){
            post_str[++len_post] = inf_str[i];
        }
        else if (inf_str[i] == '('){ //если открывающая скобка, кладем ее в стек 
            top = push(top, inf_str[i]);
        }
        else if (inf_str[i] == ')'){//если закрывающая скобка, выталкиваем все до открывающей
            while (top && top -> data != '('){
                post_str[++len_post] = top -> data;
                top = pop(top);
            }
            if (top != NULL){
                top = pop(top);
            }
        }
        else{ //иначе действем по приоритетам
            while (top && (priority(inf_str[i]) <= priority(top -> data)) && (top -> data != '(')){
                post_str[++len_post] = top -> data;
                top = pop(top);
            }
            top = push(top, inf_str[i]);
        }
    }
    while (top){//довыталкиваем все что осталось
        post_str[++len_post] = top -> data;
        top = pop(top);
    }
}


int main(void){
    OBJ* top = NULL;

    int len = 1000;
    char elts[len];
    fgets(elts, len, stdin);
    elts[strcspn(elts, "\n")] = '\0';//удаляем конечный эл-т строки
    len = strlen(elts);
    char post_str[len];

    deikstra(top, elts, len, post_str);

    puts(post_str);

    return 0;
}