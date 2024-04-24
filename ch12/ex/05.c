/*
Write a program that generates a list of 100 random numbers in the range 1–10
in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11, “Character Strings and String Functions,” to type int. In this case, just sort the numbers themselves.)
*/
#include <stdio.h>
#include <stdlib.h> /* for rand() */

void random_init(int arr[], int n);
void select_sort(int arr[], int n);
void print(int arr[], int n);

#define ARRAY_SIZE(a)  (sizeof((a))/sizeof((*a)))


int main(){
	int arr[100];

	random_init(arr, ARRAY_SIZE(arr));
	printf("Before sort, the original array is \n");
	print(arr, ARRAY_SIZE(arr));
	select_sort(arr, ARRAY_SIZE(arr));
	printf("After sort, the array is \n");
	print(arr, ARRAY_SIZE(arr));
	
	return 0;
}

void random_init(int arr[], int n) {
	for(int i =0; i < n; i++)
		arr[i] = rand() % 10 + 1;
}

void select_sort(int arr[], int n) {
	for(int i = 0; i < n - 1; i ++)
		for(int j = i + 1; j < n; j ++) {
			if (arr[j] < arr[i]){
				/* gnu c extension for type infer*/
				typeof(*arr) tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
}

void print(int arr[], int n) {
	int i;
	for(i = 0; i < n ; i++){
		printf("%3d ", arr[i]);
		if ((i % 10) == 9)
			printf("\n");
	}
	if((i % 10))
		printf("\n");
}
	
