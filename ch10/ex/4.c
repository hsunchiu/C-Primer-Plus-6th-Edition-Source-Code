/*
Write a function that returns the index of the largest value stored in an array-of-double. Test the function in a simple program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int max_index(int *array, int n);

int 
main(){
	int array[SIZE];
	
	srand(time(NULL));	
	
	for(int i = 0; i < SIZE; ++i){
		array[i] = rand() % 100;
	}
	
	printf("index of maximum in the array: ");
	for(int i = 0; i < SIZE; ++i){
		printf("%d ", array[i]);
	}
	printf(" is %d \n", max_index(array, SIZE));

	return 0;
}

int
max_index(int *array, int n){
	int index = 0; /* assume the first one is the biggest */
	for (int i = 0; i < n ; ++i ){
		if (array[i] > array[index])
			index = i;
	}
	return index;
}
		

