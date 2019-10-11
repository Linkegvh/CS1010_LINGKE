/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * <Ding Lingke>
 * <T04>
 * <This program takes in 4 integers that descripts a polynomial function 
 * as c3*x^3 + c2*x^2 + c1*x + c0
 * then returns the root value of the polynomial
 * root value here is defined as the the value of x that will make the output 0
 * 
 * I have done it in a iterative style
 * it is through checking two conditions
 * 1. if the absolute difference between the two endpoints are smaller than a pre-defined value
 * 2. if the root value is already found
 *
 * and if the two conditions are not fulfilled, it will keep on swopping the endpoints that are of same sign to the midpoint till the any of the above two conditions are met>
 */

#include <stdio.h>
#include <math.h>

//global variable as the threshold for accepting the number
float thr_h = 0.0001;

double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
	       pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	m = (a + b) / 2;
	pM = polynomial(m, c3, c2, c1, c0);

	while ( fabs(a - b) >= thr_h && pM != 0){
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);
		
		if (pM < 0){
			if (pB < 0){
				b = m;
			}else if (pA < 0){
				a = m;
			}
		}else if (pM > 0){
			if (pB < 0){
				a = m;
			}else if (pA < 0){
				b = m;
			}
		}
		
		m = (a + b) / 2;
		pM = polynomial(m, c3, c2, c1, c0);
	}

	printf("root = %.6f\n", m);
	printf("p(root) = %.6f\n", pM);

	return 0;
}

/* This function calcualtes the outcome of the polynomial function
 * the meaning of c3, c2, c1, c0 is already introduced at the start
 * num refers to the x value in the polynomial equation
 */ 
double polynomial (double num, int c3, int c2, int c1, int c0){
	double output;
	
	output = pow(num, 3) * c3 + pow(num, 2) * c2 + num * c1 + c0;

	return output;

}
