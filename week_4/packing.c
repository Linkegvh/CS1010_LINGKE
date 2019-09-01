/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * <This program will take in dimensions of the tray and slab, return the maximum number of slabs that could possibly be fitted into the tray>
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>

//below is the declaration of the two functinos that will be used by the main function
int orint_h(int DT1, int DT2, int DS1, int DS2);
int orint_v(int DT1, int DT2, int DS1, int DS2);

int main(void) {
	int max_slabs, DT1, DT2, DS1, DS2, H, V; //1 is for row and 2 is for col, H and V are the answers from the two functions indicating the maximum number of ways to arrange the slabs in a particular manner

	printf("Enter dimension of tray: "); scanf ("%d %d", &DT1, &DT2);

	printf("Enter dimension of slab: "); scanf ("%d %d", &DS1, &DS2);

	H = orint_h(DT1, DT2, DS1, DS2); V = orint_v(DT1, DT2, DS1, DS2);

	if (H > V) max_slabs = H; else max_slabs = V;

	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

//this function will take in the dimensions of the tray and slab, return the max number of slabs being able to fit onto it in the horizontal manner.
int orint_h(int DT1, int DT2, int DS1, int DS2){
	int max, row, col;

	row = DT1 / DS1; col = DT2 / DS2;
	
	max = row * col; return max;
}

//this function will take in the dimensions of the tray and slab, return the max number of slabs being able to fit onto it in the vertical manner
int orint_v(int DT1, int DT2, int DS1, int DS2){
	int max, row, col;

	row = DT1 / DS2; col = DT2 / DS1;

	max = row * col; return max;
}
