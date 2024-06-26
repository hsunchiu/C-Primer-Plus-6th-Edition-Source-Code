/*
	2. Write a program that requests your first name and does the following with it:
		a. Prints it enclosed in double quotation marks
		b. Prints it in a field 20 characters wide, with the whole field in quotes and the name at the right end of the field
		c. Prints it at the left end of a field 20 characters wide, with the whole field enclosed in quotes
		d. Prints it in a field three characters wider than the name
*/
#include <stdio.h>
#include <string.h>

int
main(){
	char first[255];

	printf("Enter your first name: ");
	scanf("%s", first);
	/* a */
	printf("\"%s\"\n", first);
	/* b */
	printf("\"%20s\"\n", first);
	/* c */
	printf("\"%-20s\"\n", first);
	/* d */
	printf("\"%*s\"\n", (int)(strlen(first) + 3), first);

	return 0;
}

