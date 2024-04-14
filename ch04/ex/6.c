/*
6. Write a program that requests the user’s first name and then the user’s last name. Have
it print the entered names on one line and the number of letters in each name on the following line. Align each letter count with the end of the corresponding name, as in the following:
	Melissa Honeybee 
	      7        8
Next, have it print the same information, but with the counts aligned with the beginning of each name.
	Melissa Honeybee 
	7       8
*/

#include <stdio.h>
#include <string.h>

int main(){

	char first[255];
	char last[255];

	printf("Please enter your first name and last name: ");
	scanf("%s%s", first, last);
	
	printf("%s %s\n", first, last);
	printf("%*d %*d\n", strlen(first), strlen(first), strlen(last), strlen(last));

	printf("%s %s\n", first, last);
	printf("%-*d %-*d\n", strlen(first), strlen(first), strlen(last), strlen(last));


	return 0;

}
