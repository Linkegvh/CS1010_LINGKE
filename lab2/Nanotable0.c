#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();

int simple_value_gather(int int_num);

int main() {
	int inter = 0; //this is intermediate value storer
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");
	while (inter != 1){
		inter = parse_command();
	}
	return 0;
}

// TO BE IMPLEMENTED: this should work in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;

	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
		return 1;
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	return 0;
}


// TO BE IMPLEMENTED: simple_sum and simple_average
// Remember to write a description for each function

/* this function will first ask for the number integers to be inputed
 * then will ask the user to input that number integers
 * then compute the sum of those integers
 * int_num is used to indicate the number of integers
 * i is a counter
 * total is the sum
 * number is the number that are inputting into the program in each cycle
 * inter is a intermediate value used in outputing the correct ordinal prefix
 */
int simple_sum() {
	int int_num, total; //declaring variables
	printf("Please indicate the number of integers:\n");
	scanf("%d", &int_num);
	total = simple_value_gather(int_num);
	printf("sum is %d\n", total);
	return 0;
}

int simple_average() {
	int int_num, total; //declaring variables and they are all referring to the same variable as in simple)sum
	float answer;
	printf("Please indicate the number of integers:\n");
	scanf("%d", &int_num);
	total = simple_value_gather(int_num);
	answer = (float) total / (float) int_num;
	if (answer - (int) answer >= 0.5){
		printf("average is %d\n", (int) answer + 1);
	}else { printf("average is %d\n", (int) answer);}
	return 0;
}

/* this function below is for simple value getter that will complement the function sum and ave
 * i is a counter
 * inter is a intermedaite value storer
 * total is the sum of all numbers inputs
 */

int simple_value_gather(int int_num){
	int i = 1, inter, total = 0, number;
	while (i <= int_num){
                printf("Please input the ");
                printf("%d", i);
                inter = i % 100;
                if (inter != 11 && inter != 12 && inter != 13){
                        if ( i % 10 == 1){
                                printf("st");
                        }else if ( i % 10 == 2){
                                printf("nd");
                        }else if ( i % 10 == 3){
                                printf("rd");
                        }else {printf("th");}
                }else {printf("th");}
                printf(" number\n");
                scanf("%d", &number);
                total = total + number;
                i++;
        }
	return total;
}
// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

