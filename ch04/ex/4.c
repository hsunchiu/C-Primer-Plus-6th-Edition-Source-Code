/*
	4. Write a program that requests your height in inches and your name, and then displays the information in the following form:
	Dabney, you are 6.208 feet tall
	Use type float, and use / for division. If you prefer, request the height in centimeters
	and display it in meters.
*/

#include <stdio.h>

int
main(){
	char name[255];
	float inches;
	printf("Please enter your name and height in inches: ");
	scanf("%s%f", name, &inches);
	printf("%s, you are %f feet tall\n", name, inches / 12.0 );

	return 0;

}
	
