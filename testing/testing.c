#include <stdio.h>
#include <ctype.h>

int main (void){
	char ch;
	printf("Enter input: ");
	ch = getchar();
	if (isdigit(ch)){
		printf("this is the output: %c\n", ch);
	}
	return 0;
}
