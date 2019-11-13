/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * <Description>
  	Input:
  		1. Number of modules
  		2. Enter above amount of module names
  		3. Enter a module name which you want to know the pre_requisite for
 	Output
 		1. The pre requisite for taking a choiced that you have choosed based on a few parameters

	Parameters:
		1. The module is of the same code name: CS and CX are different code name, CS and CS are the same code name
		2. The module is of a lower level module compared to the module of choice
 * <Ding Lingke>
 * <T04>
 */

// Add the preprocessor include statements below
#include <stdio.h>
#include <string.h>

#define MAX_MOD  10
#define MAX_LEN  7
#define TRUE 1
#define FALSE -1
#define NO_prereq 0

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);
int first_check(char [], char []);
int second_check(char [], char []);
int third_check(char [], char []);
int pre_check(char [][MAX_LEN], char [], int);

// Note: the main() function is given below. You are NOT to modify it.
int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
			 target[MAX_LEN],                 // the target module
			 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

/*
	The following code will take in two arrays and one int and a char variable.
	
	There will one pre-check to check if the target exists in the module list

	Then it will check if the first two element in the target appears in the arr list at all
		if it does not appear:
			return -1 as the entered target is invalid
		if it has appear for more than once
			conduct the second check
	
	Second check:
		check if the first digit of the element is smaller than the first digit in the target
			if it is not, move on and check the next
				if there is no next one, return -1 as there is no valid pre-req
			if it is
				conduct the third check
	
	Third check:
		check if the subsequent digit of the element is all equal to or smaller than the digits 
		in the target with the same position
			if it is not, move on and check the next
				if there is no next one, return -1 as there is no valid pre-req
			if it is
				store this element into the pre_req list
*/

int computePrereq(char arr[][MAX_LEN], int numModules, char target[], char pre_req[][MAX_LEN]){
	int i, counter = 0;
	for (i = 0; i < numModules; i ++){
		if (pre_check(arr, target, numModules) == FALSE){
			return FALSE;
		}

		if (first_check(arr[i], target) == TRUE){

			if (second_check(arr[i], target) == TRUE){

				if (third_check(arr[i], target) == TRUE){

					strcpy(pre_req[counter], arr[i]);
					counter++;

				}
			}
		}
	}

	if (counter != 0){
		return counter;
	}else{
		return NO_prereq;
	}
}

int pre_check(char arr[][MAX_LEN], char target[], int length){
	int i, counter = 0;
	for (i = 0; i < length; i++){
		if (strcmp(arr[i], target) == 0){
			counter++;
		}
	}
	if (counter == 0){
		return FALSE;
	}
	return TRUE;
}

int first_check(char arr[MAX_LEN], char target[]){
	if (strncmp(arr, target, 2) == 0){
		return TRUE;
	}
	return FALSE;
}

int second_check(char arr[MAX_LEN], char target[]){
	int a = (int) arr[2];
	int b = (int) target[2];
	if (a < b){
		return TRUE;
	}
	
	return FALSE;
}

int third_check(char arr[MAX_LEN], char target[]){
	int a, b, i;
	for (i = 3; i < MAX_LEN; i++){
		a = (int) arr[i];
		b = (int) target[i];
		if (a > b){
			return FALSE;
		}
	}
	return TRUE;
}

/**
 * ScanModules is to scan in the input from user and return the number of inputs the user has inputted as well as storing the input into a 2D array
 */
int scanModules(char arr[][MAX_LEN]){
	int num_mod, i;
	printf("Enter number of modules: ");
	scanf("%d", &num_mod);
	
	printf("Enter %d modules:\n", num_mod);
	for (i = 0; i < num_mod; i++){
		scanf("%s", arr[i]);
	}

	return num_mod;
}