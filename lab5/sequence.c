/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#define DIM 12

// Fill in the function prototypes below
void scanBoard(int [][DIM]);
void search(int [][DIM], int, int*, int*,int*);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	// call scanBoard() 
	scanBoard(board);

	// get search digit
	scanf("%d", &search_digit);

	// call search()
	search(board, search_digit, &length, &bestRow, &bestCol);

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

// this is the read data into the board and the search digit
// line by line scan
void scanBoard(int arr[][DIM]) {
	int row, col;
	for (row = 0; row < DIM; row ++){
		for (col = 0; col < DIM; col ++){
			scanf("%d", &arr[row][col]);
		}
	}
	return;
}


// the search will be done in a way that is roll search first, then col search then diagonal search
// For the searching, a few things are of interest
// 	1. if this digit that the array is currently at is the actual search digit
// 	2. resetting the count back to 0 if the digit is not the actual search digit
// 	3. after the number digits in a sequence is longer than the previous longest sequence, 
// 		some replacements must happen
// 	4. if the sequence is the same length as the previous longest sequence,
// 		check if the row of the start digit is smaller than the previous longest sequence, if yes, replace them
// during the searching, the count of consecutive search_digit is of interest
// in order to meaningfully compare, the count needs to be compared with a memory value
void search(int arr[][DIM], int search_digit, int *length_ptr, int *bestRow_ptr, int *bestCol_ptr) {
	int row, col, count = 0, count_mem = 0;
	
	// search for the best sequence in row
	for (row = 0; row < DIM; row ++){
		count = 0;
		for (col = 0; col < DIM - 1; col++){
			// check if this digit is the actual search_digit
			if (arr[row][col] == search_digit){
				count ++;
			}else{
				count = 0;
			}
			
			if (count > count_mem){
				count_mem = count;
				*bestRow_ptr = row;
				*bestCol_ptr = col - count_mem + 1;
			}else if (count == count_mem){
                                  if (row - count_mem < *bestRow_ptr){
                                          *bestRow_ptr = row;
                                          *bestCol_ptr = col - count_mem + 1;
                                  }
			}
		}
	}

	// search for the best sequence in col
	for (col = 0; col < DIM; col ++){
		count = 0;
		for (row = 0; row < DIM; row ++){
			if (arr[row][col] == search_digit){
				count++;
			}else{
				count = 0;
			}

			if (count > count_mem){
				count_mem = count;
				*bestRow_ptr = row - count_mem + 1;
				*bestCol_ptr = col;
			}else if (count == count_mem){
                                  if (row - count_mem < *bestRow_ptr){
                                          *bestRow_ptr = row - count_mem + 1;
                                          *bestCol_ptr = col;
                                  }
			}
		}
	}

	// search diagonally
	// a few things to note:
	// 	1. Must not recount the same thing as in row search and col search
	// 	2. The count only goes from left top to bottom right
	// 	3. The easiest way to search diagonal is to search diagonally and to seperate the dignal search
	// 		into two sections
	// 	4. the rest is same as the previous condition
		
		// searching the top right half of the dignal array
	row = 0;
	int i;
	for (i = 0; i < 12; i++){
		row = 0; col = i;
		count = 0;
		while (col != DIM){
				// conditions to check for
			if (arr[row][col] == search_digit){
				count++;
			}else {
				count = 0;
			}
				// increment row and col
			row ++;
			col ++;

				// checking if replacement is needed
			if (count > count_mem){
				count_mem = count;
				*bestRow_ptr = row - count_mem;
				*bestCol_ptr = col - count_mem;
			} else if (count == count_mem){
				if (row - count_mem < *bestRow_ptr){
					*bestRow_ptr = row - count_mem;
                                  	*bestCol_ptr = col - count_mem;
				}
			}	
		}
	}

		// searching the bottom left half of the dignal array
	for (i = 1; i < 12; i ++){
		col = 0; row = i;
		count = 0;
		while (col != DIM){
				// conditions to check for
			if (arr[row][col] == search_digit){
				count++;
			}else {
				count = 0;
			}

				// increment row and col
			row ++; col ++;

				// checking if replacement is needed
			if (count > count_mem){
                                 count_mem = count;
                                 *bestRow_ptr = row - count_mem;
                                 *bestCol_ptr = col - count_mem;
                        } else if (count == count_mem){
                                if (row - count_mem < *bestRow_ptr && col - count_mem < *bestCol_ptr){
                                        *bestRow_ptr = row - count_mem;
                                        *bestCol_ptr = col - count_mem;
                                }
                        }
		}
	}
	*length_ptr = count_mem;
	return;

}
