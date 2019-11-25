#include <stdio.h>
#define SIZE 5
int print_stuff (int [], int);

int main(){
    int arr[SIZE] = { 2, 1, 4, 0, 3 };
    printf("Original array: \n");
    print_stuff(arr, SIZE);
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=i+1; j<SIZE; j++) {
            printf("this is i: %d, this is j: %d\n", i, j);
            printf("This is the original one: \n");
            print_stuff(arr, SIZE);
            arr[(i+j)%SIZE] += (arr[i] + arr[j])%SIZE;
            printf("this is the new one: \n");
            print_stuff(arr, SIZE);
            printf("===================\n");
        }
    }

    print_stuff(arr, SIZE);
}

int print_stuff(int arr[], int size){
    int i;
    for (i = 0; i < size; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}