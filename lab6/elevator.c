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
#define ACTIVE 1
#define INACTIVE 0

typedef struct { 
    int status;
    int Floor;
    int Num_of_passengers;
    int usage;
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

// enable the size amount of elevators for use
void setupElevators(elevator_t elevators[], int size){
	// Incomplete
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++){
        if (i < size) {
            elevators[i].status = ACTIVE;
            elevators[i].Floor = 1;
            elevators[i].Num_of_passengers = 0;
            elevators[i].usage = 0;
            }else {
                elevators[i].status = INACTIVE;
            }
    }
    return;
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
    int i, j;
    for (i = 0; i < size; i ++){
        j = 0;
        while (sequences[i][j] != '\0'){
            goToFloor(&elevators[i], (int) (sequences[i][j] - '0'));
            j++;
        }
    }
}

void goToFloor(elevator_t *elevator, int floor){
    if ((*elevator).Floor < floor){
        if ((*elevator).Num_of_passengers + floor <= 15){
            (*elevator).Num_of_passengers += floor;
        }else{
            (*elevator).Num_of_passengers = 15;
        }
        (*elevator).Floor = floor;
    }else if ((*elevator).Floor > floor){
        if ( (*elevator).Num_of_passengers - floor >= 0){
            (*elevator).Num_of_passengers -= floor;
            (*elevator).usage += floor;
        }else{
            (*elevator).usage += (*elevator).Num_of_passengers;
            (*elevator).Num_of_passengers = 0;
        }
        (*elevator).Floor = floor;
    }
    return;
}

void printElevators(elevator_t elevators[], int size){
	// Incomplete
    int i = 0;
    while (elevators[i].status != INACTIVE){
        printf("Elevator %d:\n", i + 1); 
        printf("Floor: %d\n", elevators[i].Floor);
        printf("Number of passengers: %d\n", elevators[i].Num_of_passengers);
	    printf("Usage: %d\n", elevators[i].usage); 
        i ++;
    }
    return;
}

int mostUsedElevator(elevator_t elevators[], int size){
	// Incomplete
    int i = 0, mostUsed[2] = {0, 0};
    while (elevators[i].status != INACTIVE){
        if (i == 0){
            mostUsed[0] = elevators[i].usage;
            mostUsed[1] = i + 1;
        }else {
            if (elevators[i].usage > mostUsed[0]){
                mostUsed[0] = elevators[i].usage;
                mostUsed[1] = i + 1;
            }
        }
        i ++;
    }
	return mostUsed[1];
}
