/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * <Ding Lingke>
 * <T04>
 * <this program will take in 4 integer variabels (>= 1) in which two are a pair
 * then this program will calcualte the number square-free numbers within the range of the first and second pair
 * then the program will compare and return the pair that gives the most square-free numbers>
 */

#include <stdio.h>
#include <math.h> // optional, please remove if you are not using it

int count_square_free_number (int L, int H);
int is_square_free (int num);

int main(void) {
	int lower1, upper1, lower2, upper2;
	int first_pair, second_pair; // these are the total square-free number for the first pair of lower1 and upper1 and the second pair which is lower2 and upper2


	printf("Enter four positive integers: ");

	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);
	
	first_pair = count_square_free_number (lower1, upper1);
	second_pair = count_square_free_number (lower2, upper2);

	if (first_pair < second_pair){
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, second_pair);
	}else if (first_pair > second_pair){
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, first_pair);
	}else {
		printf("Both ranges have the same number of square-free numbers: %d\n", first_pair);
	}

	return 0;
}

/* in the below function, a range is inputed as L is the lower range and H is the higher range and the total number of square-free number is returned as variable named total
 * it is worth noting that the program will be performing iteratively
 * meaning the program will systematically check through each integer between the lower and higher range to see if it is a square-free number
 * there are 3 checks 
 * first check, check if the value is smaller than 4 as if it is, it is definately a square-free number
 * second check, check if the value is 4, if it is, it is definately a square number
 * third check, we invoke another function to check
 * and after all the integers within range is checked, the function will exit and return the total number of square number back to the main loop
 */
int count_square_free_number (int L, int H){
	int total = 0;
//	float square_root;

	while (L <= H){
		if (L < 4){
			total ++;
		}else if (L % 4 != 0){
			total = total + is_square_free (L);
		}
		L ++;
	}
	return total;	
}

/* the function below will return if this value is square free
 * When the value is not square free, it will have the same factor at least twice 
 * thus when we modulo it over one of its factors, it will return 0
 *
 * i starts at 3 because if the value is not divisable by 4, the value
 * is not gonna be divisable by 2 as well and thus it means we can skip all even numbers since even numbers are multiplies of 2
 */

int is_square_free (int num){
	int i = 3; //counter starts at 3
	while (i <= (int) sqrt(num) ){
		if ( num % (int) pow ( i, 2) == 0){
			return 0;
		}
		i = i + 2;
	}
	return 1;
}
