/*
Chuckie Lucky won a million dollars (after taxes), which he places in an account that earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a program that finds out how many years it takes for Chuckie to empty his account.
*/

#include <stdio.h>
int
main(){	
	float dollar = 100;
	const float rate = 0.08;
	int i = 0;

	while( dollar > 0){
		dollar += dollar * rate  - 10;
		i ++;
	}	

	printf("%d\n", i);
	return 0;
}
