/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * <This program computes the total number of candles that you can burnt, by using two different parameters, number of candles and number residuals to make a new candle.
 * the basic idea is that after you have burnt some candles, you can use the residual to roll up a new candle to burn later, thus, this adds more to the overall number of candles you can burn.>
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>

int count_candles (int n, int k);

int main(void) {
	int n, k;  // n stands for the number candles initially, k stands for number residuals to make a new candle
	int total; // total stands for the total number of candles brunt

	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	
	scanf("%d %d", &n, &k);
	
	total = count_candles (n, k);

	printf("Total candles burnt = %d\n", total);

	return 0;
}

/* this count_candle function will count the total amount of candles brunt
 * it is worth noting that this function works in a recursive style
 * meaning that it will recursive minus 1 from n and add 1 to total as well as a counter
 * when the counter reaches the number of residuals to make a new candle
 * the number n will be incremented by 1 & the counter will get reset back to 0
 */

int count_candles(int n, int k){
	int total = 0, k_c = 0; 

	while (n > 0){
		total ++, k_c ++;
		n --;
		if (k_c == k){
			k_c = 0;
			n ++;
		}
	}
	return total;
}
