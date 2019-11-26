#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *str1 = "app", *str2 = "pineapple";
    char *str3 = strstr(str2, str1), str4[12] = "pine";
    strcat(str4, str3);
    printf("This is str4: %s\n", str4);


    // another question
    int i;
    for (i = 0; i < 100; i ++){
        printf("random number: %d\n", rand() % 8 - 4);
    }
    return 0;
}