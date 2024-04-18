/*
Write a program that initializes a two-dimensional 3×5 array-of-double and uses a VLA- based function to copy it to a second two-dimensional array. Also provide a VLA-based function to display the contents of the two arrays. The two functions should be capable, in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable compiler, use the traditional C approach of functions that can process an N×5 array).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 5

void copy(int n, int m, double src[n][m],double dest[n][m]);
void display(int n, int m, double arr[n][m]);

int
main(){
	srand(time(NULL));

	double src[N][M];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			src[i][j] = (double)rand() / RAND_MAX * 100.0;

	display(N,M, src);

	printf("\n");
	
	double dest[N][M];
	copy(N,M, src, dest);
	
	display(N,M,dest);

	printf("\n");

	return 0;

}

/* maybe not smart */
void 
copy(int n, int m, double src[n][m], double dest[n][m]){
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			dest[i][j] = src[i][j];
}	

void
display(int n, int m, double arr[n][m]){
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			printf("%lf ", arr[i][j]);
}
