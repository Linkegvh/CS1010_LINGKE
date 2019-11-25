#include <stdio.h>
void mystery(int, int);

int main (){
    mystery(15, 3);
    return 0;
}

void mystery(int n, int b) {
    if (n != 0) {
        mystery(n / b, b);
        putchar('b' + n % b);
    }
}