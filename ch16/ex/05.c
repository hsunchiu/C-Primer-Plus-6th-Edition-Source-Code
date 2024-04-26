/*
Write a function that takes as arguments the name of an array of type int elements, the size of an array, and a value representing the number of picks. The function then should select the indicated number of items at random from the array and prints them. No array element is to be picked more than once. (This simulates picking lottery numbers or jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a similar function available, use its output with srand() to initialize the rand() random- number generator. Write a simple program that tests the function.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int * sample(int **arr, int m , int n);

int main() {
	
	int * arr = NULL;

	int m, n;

	printf("Enter M and N (M > N) \n");
	while(scanf("%d %d", &m, &n) == 2 && m > 0  && n > 0) {
		if( m < n) {
			fprintf(stderr, "M must be greater than N\n");
			
			printf("Enter M and N (M > N) \n");	
			continue;
		}	
	
	
		sample(&arr, m , n);	

		/* iterate the array search for setted */
		if (arr) {
			for (int i = 0; i < m; ++i){
				if (arr[i] > 0)
					printf("Who is the lucky Dog: %d\n", i);	
			}				
		}	
		
		free(arr);
		
		printf("Enter M and N (M > N) \n");		

	}		
	
	
	return 0;	
}
	
int * sample(int ** arr, int m, int n){

	/*malloc the array and memset all the candidated elements */
	*arr = (int *)malloc(sizeof(int) * m);
	assert(*arr);
	memset(*arr, 0, sizeof(int) * m);

	srand(time(0));
	int count = 0;

	/* try to generate n numbers */		
	while(count < n) {
		int index = random() % m;

		if( *(*arr + index) != 1){
			*(*arr + index) = 1;
			count++;
			//printf("pick no %d, count %d\n", index, count);
		}
	}
	
	return *arr;		
}

