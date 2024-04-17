/*
Using if else statements, write a program that reads input up to #, replaces each period with an exclamation mark, replaces each exclamation mark initially present with two exclamation marks, and reports at the end the number of substitutions it has made.
*/
#include <stdio.h>

#define STOP '#'

int
main(){
	int ch;
	while((ch = getchar()) != STOP){
		if (ch == '.')
			printf("!");
		else if (ch == '!')
			printf("!!");
		else
			printf("%c", ch);
	}	
	
	return 0;
}
