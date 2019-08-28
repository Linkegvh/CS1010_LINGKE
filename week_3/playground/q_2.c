#include <stdio.h>
int main(void) {
	double a,s,d,f;
	a=3.14159; 
	printf("enter the radius: ");
	scanf("%lf",&s);
	printf("enter the height: ");
	scanf("%lf", &d);
	f=(1.0/3.0)*a*s*s*d;
	printf("%.2f\n",f);
	return 0;}
