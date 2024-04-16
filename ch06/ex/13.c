/*
Write a program that creates an eight-element array of ints and sets the elements to the first eight powers of 2 and then prints the values. Use a for loop to set the values, and, for variety, use a do while loop to display the values.
*/

#include <stdio.h>

int
main(){
	int n[8];
	int i;
	for(i = 0; i < sizeof(n) /sizeof(n[0]); i++)
		n[i] = ( i + 1 ) * ( i + 1);
	
	i = 0;	
	do {
		printf("%d ", n[i]);
		i ++;
	} while(i < 8);

	printf("\n");
}
