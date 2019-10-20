/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * <Type your program description here>
 * <Ding Lingke>
 * <T04>
 */
#include <stdio.h>

// self declared functions
int compare(int, int);
int check_zero_position(int[], int);
int check_success(int[], int);
int check_status(int[], int);
int check_valid(int[], int, int);
int move_frog(int[], int);

// given functions
void printBridge(int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;

	int numMoves = 0;
	int gameState;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	/** Insert your code below **/
	gameState = 1;
	
	while (gameState == 1){
		numMoves += move_frog(bridge, lengthOfBridge);

		printf("\n======================\n");
		printf("After movement:\n");
		printBridge(lengthOfBridge, bridge);

		gameState = check_status(bridge, lengthOfBridge);

		printf("\n======================\n");
	}

	if (check_success (bridge, lengthOfBridge)){
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n", numMoves);
	}else {
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");
	}


	return 0;
}

int move_frog (int arr[100], int size){
	int pos_move, zero_pos;
	zero_pos = check_zero_position(arr, size);
	
	printf("Move the frog at position: ");
	scanf("%d", &pos_move);
	
	printf("this is zero_pos: %d", zero_pos); printf(" & this is pos_move: %d\n", pos_move);

	if (check_valid (arr, zero_pos, pos_move) == 1){
		arr[zero_pos] = arr[pos_move];
		arr[pos_move] = 0;
		return 1;
	}else {
		printf("Invalid move!\n");
		return 0;
	}
}

int check_valid (int arr[100], int zero_pos, int pos_move){
	if (arr[pos_move] == 1){
		if (zero_pos == pos_move + 1 || zero_pos == pos_move + 2){
			return 1;
		}else {
			return 0;
		}
	}else if (arr[pos_move] == -1){
		if (zero_pos == pos_move - 1 || zero_pos == pos_move - 2){
			return 1;
		}else {
			return 0;
		}
	}
	return 0;
}

int check_status(int arr[100], int size){
	int zero_pos;

	zero_pos = check_zero_position(arr, size);
	
	if ( compare(arr[zero_pos - 1], arr[zero_pos - 2]) == 2 || arr[zero_pos - 1] == 1){
		return 1;
	}else if ( compare(arr[zero_pos + 1], arr[zero_pos + 2]) == 2 || arr[zero_pos + 1] == -1){
		return 1;
	}else {
		return 0;
	}
}

int check_success (int arr [100], int size){
	int i, sign_flag[2];
	if (arr[0] != -1){
		return 0;
	}

	for (i = 0; i < size - 1; i++){
		sign_flag[0] = arr[i];
		sign_flag[1] = arr[i + 1];

		// case 1: when the two consecutive frogs are of the same clan
		// case 2: when the two consecutive frogs are of different clan
		// case 3: when the two consecutive spaces are occupied by one frog and one space

		switch ( compare(sign_flag[0], sign_flag[1]) ){
			case 1: break;
			case 2: return 0; break;
			case 3: break;
		}
	}
	return 1;
}

int check_zero_position(int arr[100], int size){
	int i;
	for (i = 0; i < size; i++){
		if (arr[i] == 0){
			return i;
		}
	}
	return 0;
}

int compare(int a, int b){
	if (a == b){
		return 1;
	}else if (a == 0 || b == 0){
		return 3;
	}else {
		return 2;
	}
}


//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

