/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * <In this program, I have implemented a bubble sort algorithm to rank different terms
 * the reason being that it will make the ranking printing easier to implement
 * other than that, I have modularised all the things that I feel can be modularised
 * so each function should only return you what the name suggest
 * two one-dimensional arrays are used as one to store the ID and one to store the scores
 * since my idea of ID is that it may not start from 1 and it may not be entered consecutively
 * thus, my code has accomodated the situations that the user does not enter ID in numerical sequences>
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

/* Function prototypes */
void print_help();
int sum_counter(int score[99], int);
int avg_counter(int score[99], int);
void iD_and_score_ranking(int ID[99], int score[99], int num_in_array); //the bubble sort

int main(void) {
  
  // The string for input command, do not modify...
  char input[MAX_COMMAND_LENGTH];

  // TO BE IMPLEMENTED
	int num_in_array = 0, avg, sum, rank, i, empty; 
	int ID[99] = {0}; int score[99] = {0};

  // print welcome information
  printf("Welcome to Nanotable!\n");
  printf("Type \"help\" for more information...\n");

  while (TRUE) {
    printf("Waiting for command...\n");
    scanf("%s", input);
		
    if (strcmp(input,"help") == 0) {
	    print_help();
    } else if (strcmp(input,"exit") == 0){
	    printf("See you!\n");
	    break;
    } else if (strcmp(input,"sum") == 0) {
	    empty = (num_in_array == 0 && ID[0] == 0 && score[0] == 0); //empty is used as it is more direct to what this line does
	    if (empty) {
		    printf("The table is empty\n");
	    } else {
		    sum = sum_counter(score, num_in_array);
		    printf("The sum of score is %d\n", sum);
	    }
    } else if (strcmp(input,"ave") == 0) {  
	    empty = (num_in_array == 0 && ID[0] == 0 && score[0] == 0);
	    if (empty) {
		    printf("The table is empty\n");
	    } else {
		    avg = avg_counter(score, num_in_array);
		    printf("The average of score is %d\n", avg);
	    }
    } else if (strcmp(input,"insert") == 0) {
	    printf("Please input the student's ID...\n");
	    scanf("%d", &ID[num_in_array]);
	    printf("Please input the student's score...\n");
	    scanf("%d", &score[num_in_array]);
	    num_in_array ++;
	    iD_and_score_ranking(ID, score, num_in_array);
    } else if (strcmp(input,"init") == 0) {
	    printf("Initializing table...\n");   
	    for (i = 0; i <= 99; i++){
		    ID[i] = 0;
		    score[i] = 0;
	    }
	    num_in_array = 0;
    } else if (strcmp(input,"rank") == 0) {
	    empty = (num_in_array == 0 && ID[0] == 0 && score[0] == 0);
	    if (empty) {        
		    printf("The table is empty\n");
	    } else {
		printf("Please input the rank (1 - %d)...\n", num_in_array);
		scanf("%d", &rank);
		while (rank > num_in_array){
			printf("Invalid rank: %d\n", rank);
			printf("Please input the rank (1 - %d)...\n", num_in_array);
			scanf("%d", &rank);
		}
		printf("ID: %d, Score: %d\n", ID[rank - 1], score[rank - 1]);
	    }
    } else {
	    printf("No such command: %s, please input command again!\n", input);
    }
  }
  return 0;
}

// this function prints the menu for help
void print_help() {
       	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
	return;
}

//this function sums up all the values in the scores
int sum_counter(int score[99], int num_in_array){
	int sum = 0, i;
	for (i = 0; i <= num_in_array; i++){
		sum += score[i];
	}
	return sum;
}

//this function uses the sum from the previous function to divide over the amount of numbers in the array to get the average
int avg_counter(int score[99], int num_in_array){
	float avg_raw;
	int avg, sum;
	sum = sum_counter(score, num_in_array);
	avg_raw = (float) sum / (float) num_in_array;
	avg = (int) avg_raw;
	
	// to accomodate for the rounding up issue
	if (avg_raw - avg >= 0.5){
		avg ++;
	}
	return avg;
}

//the bubble sort algorithm to sort through ID array and score array
void iD_and_score_ranking (int ID[99], int score[99], int num_in_array){
	int i, j, swap;
	for (i = 0; i < num_in_array - 1; i++){
		for (j = 0; j < num_in_array - i - 1; j++){
			if (score[j] > score[j + 1]){
				// swapping the score array
				swap = score[j];
				score[j] = score[j+1];
				score[j+1] = swap;
				// swapping the ID array
				swap = ID[j];
				ID[j] = ID[j+1];
				ID[j+1] = swap;
			}
		}
	}
	return;
}
