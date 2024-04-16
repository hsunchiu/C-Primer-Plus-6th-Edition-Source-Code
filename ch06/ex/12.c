/*
Consider these two infinite series:
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
Write a program that evaluates running totals of these two series up to some limit of number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself an even number of times is 1. Have the user enter the limit interactively; let a zero or negative value terminate input. Look at the running totals after 100 terms, 1000 terms, 10,000 terms. Does either series appear to be converging to some value?

*/

#include <stdio.h>

int
main(){
	long int limit;
	float series1 = 0;
	float series2 = 0;
	float start = 1.0;
	float sign = 1.0f;
	printf("Enter the limit for the series: ");
	
	scanf("%ld", &limit);
	
	for(long int i = 0; i <= limit; i ++){
		series1 += 1.0 / (1.0 * (i + 1));
		series2 += 1.0 / (1.0 * (i + 1)) * sign ;
		sign = -sign; /* toggle the sign */
	}
	
	printf("%f %f\n", series1, series2);

	return 0;
}
		
