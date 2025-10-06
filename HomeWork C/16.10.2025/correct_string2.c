#include <stdio.h>

int correct_string(int len, char* str, char open, char close){
    int flag;
    flag = (str[0] != open && str[0] != close) ? 0 : str[0] == open ? 1 : -1;
    if (flag == -1){
        return -1;
    }
    for (int i = 1; i < len; ++i){
        if (flag <= -1){
            return -1;
        }
        if (str[i] == open){
        ++flag;
        }
        if (str[i] == close){
        --flag;
        }
    }
    return flag;
}

int main(void){
    int len, flag;
    printf("enter the length of the string and the string: ");
    scanf("%d ", &len);
    char str[len];
    scanf("%s", &str);
    flag = correct_string(len, str, '(', ')') == 0 && correct_string(len, str, '[', ']') == 0 && correct_string(len, str, '{', '}') == 0;
    if (flag == 1){
        printf("correct string");
    }
    else{
        printf("incorrect string");
    }
    return 0;
    }
