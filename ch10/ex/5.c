/*
Write a function that returns the difference between the largest and smallest elements of an array-of-double. Test the function in a simple program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

double random_double(double min, double max);
double max_difference(double * arr, int n);

int
main(){
	double arr[SIZE];	
		
	srand(time(NULL));
	for(int i=0; i<SIZE; ++i){
		arr[i] = random_double(0.0, 100.0); 
	}

	printf("Max difference of the array: ");
	for(int i=0; i<SIZE; ++i){
		printf("%lf ", arr[i]);
	}

	printf(" is %lf\n", max_difference(arr, SIZE));

	return 0;
}

double 
random_double(double min, double max){
	return ((max -min) * ((double) rand() / RAND_MAX)) + min;
}

double
max_difference(double * arr, int n){
	int max = arr[0];
	int min = arr[0];
	
	for(int i=0; i<n ; ++i){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];

	}
	return max - min;

}
		
