#include <stdio.h>

int main (void){
	float Input;
	float One_Dollar = 1.0, Fifty_cent = 0.5, Twenty_cent = 0.2, Ten_cent = 0.1, Five_cent = 0.05;
	int N_One_Dollar = 0, N_Fifty_cent = 0, N_Twenty_cent = 0, N_Ten_cent = 0, N_Five_cent = 0;
	
	printf("Please put in a positive number:");
	scanf ("%f", &Input);
	printf("\n");
	while (Input > 0){
		if (Input - One_Dollar >= 0){
			Input = Input - 1.0;
			N_One_Dollar ++;
		}else if (Input - Fifty_cent >= 0) {
			Input = Input - 0.5;	
			N_Fifty_cent ++;
				}else if (Input - Twenty_cent >= 0){
					Input = Input - 0.2;
					N_Twenty_cent ++;
				}else if (Input - Ten_cent >= 0){
					Input = Input - 0.1;
					N_Ten_cent ++;
				}else if (Input - Five_cent >=0){
					Input = Input - 0.05;
					N_Five_cent ++;
				}else {
					printf("This number will give rise to coins that are too small to exist in SG\n");
					Input = 0;
				}
		}
	printf("This is the calculation done to show the number of coins we need and the number of the individual coins.\n");
	printf("Total Number of Coins is %d\n", N_One_Dollar + N_Fifty_cent + N_Twenty_cent + N_Ten_cent + N_Five_cent);
	printf("Number of One dollar coins is %d\n", N_One_Dollar);
	printf("Number of Fifty Cent coins is %d\n", N_Fifty_cent);
	printf("Number of Twnty Cent coins is %d\n", N_Twenty_cent);
	printf("Number of Ten Cent coins is %d\n", N_Ten_cent);
	printf("Number of Five Cent coins is %d\n", N_Five_cent);
	return 0;
}
