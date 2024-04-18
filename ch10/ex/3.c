/*
Write a function that returns the largest value stored in an array-of-int. Test the function in a simple program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int max(int * array, int n);

int
main(){
	int array[SIZE];
	
	srand(time(NULL)); /* seed random number generator */

	for( int i = 0; i < SIZE; ++i){
		array[i] = rand() % 100;
	}
	
	printf("The maxium of \n");
	for (int i =0; i < SIZE; ++i){
		printf("%d ", array[i]);
	}
	printf("\nis %d\n", max(array, SIZE));

	return 0;
}

int max(int *array, int n){
	int biggest = array[0];
	for (int i=0; i < n ; ++i){
		if (biggest < array[i])
			biggest = array[i];
	}
	return biggest;
}
		
