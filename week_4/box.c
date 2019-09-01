/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex2
 * box.c
 * <This program takes in three integer values as length, width and height of a box and returns the surface area as well as a two dp diagonal lenth of the box>
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#include <math.h>

//below are function declarations
int SA_CAL (int L, int W, int H);
double D_CAL (int L, int W, int H);

int main(void) {
	int L, W, H, SA; //SA stands for surface area, the rest is self-explanatory

	double D; 

	printf("Enter length: "); scanf("%d", &L); 

	printf("Enter width : "); scanf("%d", &W);

	printf("Enter height: "); scanf("%d", &H);

	SA = SA_CAL(L, W, H); D = D_CAL(L, W, H);

	printf("Surface area = %d\n", SA); printf("Diagonal = %.2lf\n", D);
	
	return 0;
}

//This functions takes in three integer values in the order of Length, Width and Height, then returns the surface area of the box

int SA_CAL(int L, int W, int H){
	int SA;

	SA = L * W * 2 + L * H * 2 + W * H * 2; //following the formula found online to calculate the box surface area

	return SA;
}

//This functions takes the same variables but returns a type double diagonal of the box
double D_CAL(int L, int W, int H){
	double D;
	
	D = pow ( (L * L + W * W + H * H) , 0.5); //following the diagonal formula which can be checked out online
	return D;
}
