/*
Design and test a function that searches the string specified by the first function parameter for the first occurrence of a character specified by the second function parameter. Have the function return a pointer to the character if successful, and a null if the character is not found in the string. (This duplicates the way that the library strchr() function works.) Test the function in a complete program that uses a loop to provide input values for feeding to the function
*/
#include <stdio.h>

char *strchr(char *s, char c) {
	char * ret = NULL;

	while(*s){
		if (*s == c){
			ret = s;
			break;
		}	
		s++;
	}

	return ret;

}	

int
main(){
	
	char *s =  "hello world";
	char *find;
	
	if ((find = strchr(s, 'w'))){
		printf("Find w in the string \"%s\", postition: %ld \n", s, find -s);
	}

	return 0;
}

