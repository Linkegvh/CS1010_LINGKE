#include <stdio.h>

int f(int);

int main (){
    int a = f(13);
    printf("this is the output: %d\n", a);
    return 0 ;
}

int f (int n){
    switch (n % 4){
        case 0: return n;
        case 2: return 2 * f(n/4);
        default: return f(n - 1) + f (n + 1);
    }
}