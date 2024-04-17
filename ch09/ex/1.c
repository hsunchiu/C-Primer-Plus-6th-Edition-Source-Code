/*
Devise a function called min(x,y) that returns the smaller of two double values. Test
the function with a simple driver.
*/

#include <stdio.h>

double min(double, double);

int
main(){
	double x, y;

	printf("Enter two doubles(non-double input to quit): ");
	
	while(scanf("%lf%lf", &x, &y) == 2){
		printf("The minimum of %.3f and %.3f is %.3f.\n", x, y, min(x,y));
		printf("Enter two doubles (non-double input to quit): ");
	}

	return 0;
}

double
min(double x, double y){
	return x < y ? x : y;
}
