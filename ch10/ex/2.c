/*
Write a program that initializes an array-of-double and then copies the contents of the array into three other arrays. (All four arrays should be declared in the main program.) To make the first copy, use a function with array notation. To make the second copy, use a function with pointer notation and pointer incrementing. Have the first two functions take as arguments the name of the target array, the name of the source array, and the number of elements to be copied. Have the third function take as arguments the name
of the target, the name of the source, and a pointer to the element following the last element of the source. That is, the function calls would look like this, given the following declarations:
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5); 
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5);

*/
#include <stdio.h>

void copy_arr(double dest[], double src[], int n);
void copy_ptr(double * dest, double *src, int n);
void copy_ptrs(double * dest, double * start, double *end);
void printarray(double * dest, int n);

int
main(){
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);	

	printarray(target1, 5);
	printarray(target2, 5);
	printarray(target3, 5);
	
	return 0;
}
	
void
copy_arr(double dest[], double src[], int n){
	for (int i = 0; i < n; ++i){
		dest[i] = src[i];
	}
}

void 
copy_ptr(double * dest, double * src, int n){
	int i= 0;
	while( i++ < n) {
		*dest++ = *src++;
	}
}


void 
copy_ptrs(double *dest, double *start, double *end){
	while(start < end){
		*dest++ = *start++;
	}
}

void printarray(double * array, int n){
	for (int i = 0; i < n ; ++i){
		printf("%lf ", *(array + i));
	}
	printf("\n");
}
