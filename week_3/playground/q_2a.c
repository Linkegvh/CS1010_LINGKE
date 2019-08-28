#include <stdio.h>
int main(void) {
	// declare the int variables num1, num2 and num3
	float num1, num2, num3;
	// ask user to enter two values into num1 and num2
	printf("Enter two real numbers: ");
	scanf("%f %f", &num1, &num2);
	num3 = 0.0; // initialise num3 to 0.0
	// divide num1 by num2, then multiply the result by num2
	// and then assign the result to num3
	num3 = (num1/num2) * num2;
	printf("num3 = %f\n", num3); // display value in num3
	return 0; }
