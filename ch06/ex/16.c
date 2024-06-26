/*
Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest compounded annually. (That is, interest is 5% of the current balance, including previous addition of interest.) Write a program that finds how many years it takes for the value
of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two values at that time.
*/

#include <stdio.h>

int
main(){
	int i = 0;
	double daphe = 100;
	double deirdre = 100;
	
	while(daphe >= deirdre){
		daphe += 100.0 * 0.1;
		deirdre += deirdre * 0.05;
		i ++;
	} 
	
	printf("After %d years, Daphne's investment is worth $%.2f and "
		   "Deirdre’s investment is worth $%.2f.\n", i, daphe, deirdre);

	return 0;
}
		
