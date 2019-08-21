// Unit3_prog1.c
// This program computes the average of 3 integers
#include <stdio.h>

int main(void) {
	int num1, num2, num3;
	float ave;

	printf("Enter 3 integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	ave = (num1 + num2 + num3) / 3.0;
	printf("Average = %.2f\n", ave);

	return 0;
}

