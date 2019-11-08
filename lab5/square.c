/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#define MAXSIZE 9
#define it_is_a_semi_magic_square 1
#define it_is_not_a_semi_magic_square 0

int scanSquare(int [][MAXSIZE]);
int isSemiMagic(int [][MAXSIZE], int);
int find_same_num(int num, int arr[][MAXSIZE], int size);
int all_element_same_or_not(int row[], int col[], int size);

int main(void) { 
	// Use the following printf statements 
	// for printing the output.
	int arr[MAXSIZE][MAXSIZE];
       	int arr_size, result;
	
	// get input & size of the arr
	arr_size = scanSquare(arr);
	
	// check if the arr is a semi magic array
	result = isSemiMagic(arr, arr_size);
	
	if (result == it_is_not_a_semi_magic_square){
		printf("It is not a semi-magic square.\n");
	}else if (result == it_is_a_semi_magic_square){
		printf("It is a semi-magic square.\n");
	}
	
	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}

/* there are a few conditions to be semi-magic
 * the first condition
 * 	Contains all the numbers within size^2
 * 	in other words, there is no repeated number
 * 
 * the second condition
 * 	all the rows and columns sum to the same number
 */

int isSemiMagic(int arr [][MAXSIZE], int size){
	int row, col, result, row_sum[size], col_sum[size];
	
	// checking for first condition
	for (row = 0; row < size; row++){
		for (col = 0; col < size; col++){
			result = find_same_num(arr[row][col], arr, size);
			if (result == 1){
				return it_is_not_a_semi_magic_square;	
			}
		}
	}

	// checking for second condition
	
	// this is for the row_sum list
	for (row = 0; row < size; row++){
		row_sum[row] = 0;
		for (col = 0; col < size; col++){
			row_sum[row] += arr[row][col];
		}
	}
	// this is for the col_sum list
	for (col = 0; col < size; col++){
		col_sum[col] = 0 ;
		for (row = 0; row < size; row++){
			col_sum[col] += arr[row][col];
		}
	}
	// this is to check if all the numbers in the row and col list are the same number
	result = all_element_same_or_not(row_sum, col_sum, size);
	if (result == 1){
		return it_is_not_a_semi_magic_square;
	}

	return it_is_a_semi_magic_square;
}


// to find if there exist more than one same number (other than itself) in the array
int find_same_num(int num, int arr[][MAXSIZE], int size){
	int row, col, count = 0;
	for (row = 0; row < size; row++){
		for (col = 0; col < size; col++){
			if (arr[row][col] == num){
				count ++;
			}
		}
	}
	if (count >= 2){
		return 1;
	}
	return 0;
}

// to find if all the elements in the two list are the same number
int all_element_same_or_not(int row[], int col[], int size){
	int r, c;
	for (r = 0; r < size; r ++){
		for (c = 0; c < size; c ++){
			if (row[r] != col[c]){
				return 1;
			}
		}
	}
	return 0;
}
