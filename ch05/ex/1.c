/*
Write a program that converts time in minutes to time in hours and minutes. Use #define or const to create a symbolic constant for 60. Use a while loop to allow the user to enter values repeatedly and terminate the loop if a value for the time of 0 or less is entered.
*/

#include <stdio.h>

/* 1 hour is 60 minutes */
#define H2M_SCALE 60

int
main(){
	int minutes = 0;
	printf("Enter minutes (0 or less than 0 quit): ");
	scanf("%d", &minutes);

	while(minutes > 0){
		printf("%d minute(s): %d hour(s) %d minute(s) \n", minutes, minutes / H2M_SCALE, minutes % H2M_SCALE);
		printf("Continue...\nEnter 0 or less than 0 to quit!\n");
		if (scanf("%d", &minutes) == 0) break;
		
	}
	
	return 0;
}

