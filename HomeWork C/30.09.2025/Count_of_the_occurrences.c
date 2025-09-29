#include <stdio.h>
#include <string.h>

int count_occurrences(char *S, char *S1){
    int count = 0;
    char *pos = S;
    while ((pos = strstr(pos, S1)) != NULL){
        ++count;
        ++pos;
    }
    return count;
}

int main(void){
    char S[32000], S1[32000];

    printf("enter the string S: ");
    fgets(S, sizeof(S), stdin);

    printf("enter the string S1: ");
    fgets(S1, sizeof(S1), stdin);

    S[strcspn(S, "\n")] = '\0';
    S1[strcspn(S1, "\n")] = '\0';

    int res = count_occurrences(S, S1);

    printf("the count of occurrences s1 in s is: %d ", res);

    return 0;
}

