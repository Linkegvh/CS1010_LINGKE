#include <stdio.h>

int main(){
    char D = 'H', H = 'D';
    printf("This is the original output %d\n", D + (D-H) / 2);
    printf("this is 'H' - 'D': %d\n", D - H);
    return 0;
}