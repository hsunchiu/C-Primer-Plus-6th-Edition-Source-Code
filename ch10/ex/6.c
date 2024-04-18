/*
Write a function that reverses the contents of an array of double and test it in a simple program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void reverse(double * arr, int n);


int
main(){
	double arr[SIZE];

	srand(time(NULL));
	
	for(int i=0; i<SIZE; i++){
		arr[i] = (double) rand() / RAND_MAX * 100.0;
	}
	
	printf("The array before reversed: ");
	for(int i=0; i< SIZE; i++){
		printf("%lf ", arr[i]);
	}
	reverse(arr, SIZE);

	printf("\nThe array after reversed: ");
	for(int i=0; i<SIZE; i++){
		printf("%lf ", arr[i]);
	}
	
	printf("\n");
	
	return 0;
}

void reverse(double * arr, int n){
	for(int i=0; i < n/2; i++){
		/* swap the double */
		double temp;
		temp = arr[i];
		arr[i] = arr[n-1 -i];
		arr[n-1 -i] = temp;
	}
}
	
