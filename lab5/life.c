/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex3
 * Game of Life
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>

#define DIM_ROW 20
#define DIM_COL 20
#define DEAD    '-'
#define LIFE    'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);

int main(void) {
	char board[DIM_ROW+2][DIM_COL+2]; // the community
	int  lives;                       // how many lives in community
	int  generation = 0;              // generation

	lives = genesis(board);
	// display(generation, board); // for checking



	// Display the final generation
	display(generation, board); 

	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) {
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) {
	int r, c;

	printf("Generation %d:\n", generation);
	for (r=1; r <= DIM_ROW; r++) {
		for (c=1; c <= DIM_COL; c++) {
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To generate next generation and
// return number of live cells in next generation.
// next_generation()

