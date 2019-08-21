// Unit3_prog2.c
// This program arranges 2 integers in ascending order
#include <stdio.h>

int main(void) {
	int num1, num2, temp;

	printf("Enter 2 integers: ");
	scanf("%d %d", &num1, &num2);

	if (num2 < num1) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	printf("Sorted: num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}

