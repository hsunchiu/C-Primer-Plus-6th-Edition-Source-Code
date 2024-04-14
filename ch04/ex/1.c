/* Write a program that asks for your first name, your last name, and then prints the names
in the format last, first. */

#include <stdio.h>

int
main(){
	char first[255];
	char last[255];
	printf("Enter your first name and last name: ");
	scanf("%s%s", first, last);
	printf("%s, %s\n", first, last);

	return 0;
}
	
