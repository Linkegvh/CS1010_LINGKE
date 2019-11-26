#include <stdio.h>


int minMax (int [], int, int *);

int main (){
    int min, max = 0;
    int arr[] = {3, 2, 1, 4, 5};

    min = minMax (arr, 5, &max);

    printf("Minimum is ( %d ), ", min);
    printf("and maximum is ( %d ).\n", max);
    printf("This is * ( &max) %d\n", *(&max));
    return 0;
}

int minMax(int arr[], int size, int *max){
    int i, min;

    min = arr[0];
    *max = arr[0];
    printf("this is max: %p\n", max);

    for (i = 1; i < size; i ++){
        if (arr[i] > *max){
            *max = arr[i];
            printf("this is max new: %d\n", *max);
        }else if (arr[i] < min){
            min = arr[i];
        }
    }
    printf("this is max last: %p\n", max);
    printf("this is max last: %d\n", *max);
    return min;
}