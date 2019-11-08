#include <stdio.h>

int main(void){
	int a, b, c;
	b = 0;
	a = b;
	c = 1;
	b = c;

	printf("a: %d, b: %d, c: %d\n",a,b,c);
	return 0;
}
