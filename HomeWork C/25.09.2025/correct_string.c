#include <stdio.h>

int main(void){
    int len, flag;
    printf("enter the length of the string and the string: ");
    scanf("%d ", &len);
    char str[len];
    scanf("%s", &str);
    flag = (str[0] != '(' && str[0] != ')') ? 0 : str[0] == '(' ? 1 : -1;
    if (flag == -1){
        printf("incorrect string");
        return 0;
    }
    for (int i = 1; i < len; ++i){
        if (flag <= -1){
            printf("icorrect string");
            return 0;
        }
        if (str[i] == '('){
        ++flag;
        }
        if (str[i] == ')'){
        --flag;
        }
    }
    if (flag == 0){
        printf("correct string");
    }
    else{
        printf("incorrect string");
    }
    return 0;
    }