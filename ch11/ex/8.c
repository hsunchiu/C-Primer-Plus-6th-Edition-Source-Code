/*
Write a function called string_in() that takes two string pointers as arguments. If
the second string is contained in the first string, have the function return the address
at which the contained string begins. For instance, string_in("hats", "at") would return the address of the a in hats. Otherwise, have the function return the null pointer. Test the function in a complete program that uses a loop to provide input values for feeding to the function.
*/
#include <stdio.h>
#include <string.h>

#define LIMIT 50

char * string_in(char *string, char *substring);
char * get(char *string, int n);

int
main(){
	char string[LIMIT];
	char substring[LIMIT];

	char *substr_loc;

	printf("Enter a string: ");
	get(string, LIMIT);
	while (string[0] != '\0')
	{
		printf("Enter a substring to look for: ");
		get(substring, LIMIT);

		substr_loc = string_in(string, substring);

		if (substr_loc == NULL)
			printf("%s not in %s\n", substring, string);
		else
			printf("%s found in %s at index %lu\n",
				   substring, string, substr_loc - string);

		printf("Enter a string (empty line to quit): ");
		get(string, LIMIT);
	}

	puts("Bye");

	return 0;
	
}


char * string_in(char *s1, char*s2) {

	while(*s1) {

		int i = 0;
		while(s1[i] == s2[i]){
			i++;

			if(s2[i] == '\0')
				return s1;
		}
		s1 ++;
	}	
	

	return NULL;
	
}	

char * get(char *string, int n)
{
	// wrapper for fgets that replaces first newline with null

	char *return_value = fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}

		string++;
	}

	return return_value;
}
