#include <stdio.h>
#define SIZE 10
void bubbleSort(int * const array, const int size);
void swap(int *element1Ptr, int *element2Ptr);
int main(void){

   int arr[SIZE] = {2, 3, 9, 4, 1, 5, 7, 12, 18, 15};
   int i;

   printf("Original array values\n\n");
   for(i=0; i<SIZE; i++){
      printf("%d\n", arr[i]);
   }

   bubbleSort(arr, SIZE);
 
   printf("\n\nSorted array values\n\n");
   for(i=0; i<SIZE; i++){
      printf("%d\n", arr[i]);
   }
 
}
 
void bubbleSort(int * const array, const int size){
   int pass, i=0;
 
   for(pass=0; pass < size-1; pass++){
 
      for(i=0; i < size-1; i++){
 
         if(array[i] > array[i+1]){
            swap(&array[i], &array[i+1]);
         }
      }
   }
}
 
void swap(int *element1Ptr, int *element2Ptr){
   int hold;
   hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
}
