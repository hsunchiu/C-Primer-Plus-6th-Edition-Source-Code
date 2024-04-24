/*
Write a function that replaces the contents of a string with the string reversed. Test the function in a complete program that uses a loop to provide input values for feeding to the function.
*/

#include <stdio.h>

void reverse_str(char *s);


int main(){

	char line[81];

	printf("Enter a line:\n");
	
	while(scanf("%80s", line) == 1) {
		printf("Before Reverse is \"%s\"", line);
		printf("'\n");
		/* in place reverse */
		reverse_str(line);
		printf("After  Reverse is \"%s\"", line);

		printf("\n");
		/* eat line */
		while(fgetc(stdin) != '\n');

	}
}


void reverse_str(char *s){
	/* get the line first */
	int len = 0;

	while( *(s + len) != '\0') {
		len ++;
	}
	
	if (len < 2)
		return;

	/* in place reverse */
	int mid = len / 2; 

	for(int i = 0; i < mid; i++) {
		char temp;
		temp = *(s + i);
		*(s + i) = *(s + len -1 -i);
		*(s + len -1 -i) = temp; 
	}	
}
