/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * <Type a description of the program here>
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	// Incomplete
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevators(elevators, size);
	readSequences(sequences, size);
	
	runElevators(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}

void setupElevators(elevator_t elevators[], int size){
	// Incomplete
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	// Incomplete
}

void goToFloor(elevator_t *elevator, int floor){
	// Incomplete
}

void printElevators(elevator_t elevators[], int size){
	// Incomplete
	printf("Elevator :\n"); 
	printf("Floor: \n");
	printf("Number of passengers: \n");
	printf("Usage: \n");
}

int mostUsedElevator(elevator_t elevators[], int size){
	// Incomplete
	return 1;
}
