/*
Write a program that creates two eight-element arrays of doubles and uses a loop to let the user enter values for the eight elements of the first array. Have the program set the elements of the second array to the cumulative totals of the elements of the first array. For example, the fourth element of the second array should equal the sum of the first four elements of the first array, and the fifth element of the second array should equal the sum of the first five elements of the first array. (It’s possible to do this with nested loops, but by using the fact that the fifth element of the second array equals the fourth element of the second array plus the fifth element of the first array, you can avoid nesting and just use a single loop for this task.) Finally, use loops to display the contents of the two arrays, with the first array displayed on one line and with each element of the second array displayed below the corresponding element of the first array.
*/

#include <stdio.h>

int
main(){
	double n1[8];
	double n2[8];
	printf("Enter eight-element for the double array: ");
	
	int i;

	// read 8 double integers
	for ( i = 0; i < 8; i ++){
		scanf("%lf", &n1[i]);
	}

	for ( i = 0; i < 8; i ++) {
		if (!i )
			n2[i] = n1[i];
		else
			n2[i] = n2[i -1] + n1[i];
	}

	for ( i = 0; i < 8; i ++ ){
		printf("%10lf", n1[i]);
	}
	printf("\n");
	for (i = 0; i  <8; i ++){
		printf("%10lf", n2[i]);
	}
	printf("\n");	
	return 0;
}
	
