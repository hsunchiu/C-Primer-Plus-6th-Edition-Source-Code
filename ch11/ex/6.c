/*
Write a function called is_within() that takes a character and a string pointer as its two function parameters. Have the function return a nonzero value (true) if the character is
in the string and zero (false) otherwise. Test the function in a complete program that uses a loop to provide input values for feeding to the function.
*/

#include <stdio.h>
#include <stdbool.h>

bool is_within(char c, char *s);

int
main(){

	printf("Enter a string and a character: ");

	char word[81];

	char c;	
	
	while((scanf("%s %c", word, &c)) == 2) {
		printf("%c in %s ? %s\n", c, word,
		is_within(c, word) ? "true" : "false");

		while(getchar() != '\n');
	}	
}


bool is_within(char c, char *s) {
	while(*s){
		if(*s == c){
			return true;
		}else{
			s++;
		}
	}
	return false;
}
