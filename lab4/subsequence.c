/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * <Lingke>
 * <T04>
 */

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// Write a description for this function below
// ...
// Objective:
//            This function returns the maximum sum of a k-interval subsequence among all k-interval subsequences
// 
// Mechanism:
// 		This function is implemented using a looping concept. This function loops through different interval
// 		and the different subsequences within that particular interval
// 		then calcualtes the sum of all values in that particular subsequences
// 		then compared that with the sum of all values in the last subsequences
// 			if the sum of this particular subsequences if greater, it will replace the sum value of the last subsequences
// 			else, the sum of this particular subsequences will get ignored
// 		In the mean time, the interval number and start position will all get update if the sum is updated
//
// 		After looping through all the possible subsequences, this function will give the value in variable sum, interval & start_pos to answer[0], [1] & [2]. 
//
// ...
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	// inter_sum --> a temperory value holder for the sum of a particular interval subsequence
	int inter_sum;

	// sum, interval, start_pos --> refers to answer[0], answer[1] and answer[2] respectively
	int sum = 0, interval, start_pos;

	// start --> the starting position for a particualr interval subsequence
	// the value of start changes when we have finish the calcualtion for one subsequence and 
	// move onto the next subsequence
	int start;

	// total_num --> the total number of numbers that we have included in this particular interval. 
	// the maximum it can possibly be is the size of the whole arr[]
	int total_num;
	
	// i = number k of the interval --> an incremental constant that helps to loop between different intervals
	// it will start from 1, as the 1-interval, then proceed to 2, as the 2-interval 
	// it will increment till n interval till there is only single value in the interval list
	// j --> a constant that increments to obtain the different value in the interval subsequence
	int i, j; 
	
	
	for (i = 1; i <= size; i++){
		start = 0;
		j = 0;
		total_num = 0;
		while (total_num < size){
			inter_sum = 0;
			for (j = start; j < size; j+=i){
				inter_sum += arr[j];
				total_num ++;
			}
			if (inter_sum > sum) {
				sum = inter_sum;
				interval = i;
				start_pos = start;
			}
			start ++;
		}

	}
	
	ans[0] = sum;
	ans[1] = interval;
	ans[2] = start_pos;

	return;
}

