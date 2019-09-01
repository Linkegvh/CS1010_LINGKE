/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#include <math.h>

int main(void) {
	int principal, rate, numYears;
	float AMT, Deno; //deno stands for denominator

	printf("Enter principal amount: "); scanf("%d", &principal);
	
	printf("Enter interest rate   : "); scanf("%d", &rate);

	printf("Enter number of years : "); scanf("%d", &numYears);
	
	//Deno calculates the denometer part of the equation while AMT uses the deno answer to calculate out the full complete answer
	
	Deno = principal * ( 1 - (pow ( ( (double)rate / 100), (numYears + 1) ) ) );

	AMT = Deno / ( 1 - ( (float) rate / 100) );

	printf("Amount = $%.2f\n", AMT);
	
	return 0;
}

