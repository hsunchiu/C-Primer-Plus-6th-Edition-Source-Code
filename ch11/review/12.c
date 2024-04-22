/*
Design a function that takes a string pointer as an argument and returns a pointer to the first space character in the string on or after the pointed-to position. Have it return a null pointer if it finds no spaces.
*/
#include <stdio.h>

char * strspace(char *s){
	char * ret = NULL;

	while(*s){
		if (*s == ' '){
			ret = s;
			break;
		}
		s++;		
	}
	
	return ret;
}

int main(){
	char line[81];

	printf("Enter a line, return the position of the first space\n");

	/* Don't eat the line */	
	while(fgets(line, 81, stdin) != NULL) {
		char * find = strspace(line);
		if(find)
			printf("the first space in the string is %ld \n", find - line);
		else
			printf("Can't find space in the input string\n");

	}
	
	return 0;
}

	



