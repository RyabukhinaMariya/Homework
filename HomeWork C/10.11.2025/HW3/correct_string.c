#include <stdio.h>

int is_correct(char *str, int *flag){
    int last_pos = 0;
    flag[0] = 0;

    for (int i = 0; i < sizeof(str)/2; ++i){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
                ++flag;
                flag[last_pos] = (int) str[i];
            }
        else if (str[i] == ')' || str[i] == '}' || str[i] == '}'){
            if (flag[last_pos] - (int) str[i] == -1 || flag[last_pos] - (int) str[i] == -2){
                flag[last_pos] = 0;
                --last_pos;
            }
            else{
                return 0;
            }
        }
    }
    if (flag[last_pos] == 0){
            return 1;
    }
    else{
        return 0;
    }
}


int main(void){

    int len;
    printf("enter the length of the string and the string: ");
    scanf("%d ", &len);
    char str[len];
    scanf("%s", &str);

    int flag[len/2+1];

    if (is_correct(str, flag) == 1){
        printf("correct string");
    }
    else{
        printf("incorrect string");
    }

    return 0;
    }
