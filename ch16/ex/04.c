/*
 he ANSI library features a clock() function with this description: #include <time.h>
clock_t clock (void);
Here, clock_t is a type defined in time.h. The function returns the processor time, which is given in some implementation-dependent units. (If the processor time is unavailable or cannot be represented, the function returns a value of -1.) However, CLOCKS_PER_SEC, also defined in time.h, is the number of processor time units per second. Therefore, dividing the difference between two return values of clock() by CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls. Typecasting the values to double before division enables you to get fractions of a second. Write a function that takes a double argument representing a desired time delay and
then runs a loop until that amount of time has passed. Write a simple program that tests the function.

*/


#include <stdio.h>
#include <time.h>
void delay(double second);

int main(){

	time_t start = clock();
	for(int i=0; i< 10; ++i){
		printf("loop...\n");
		delay(1);
	}
	
	printf("About %lf seconds elapsed.\n", (clock() - start) / (double)CLOCKS_PER_SEC);
	return 0;
}


void delay(double second) {
	clock_t start = clock();
	/* busy loop */
	//while(1){
	//	clock_t elapse = clock() - start;
	//	if (elapse / (double) CLOCKS_PER_SEC  > time)
	//		break;
	//} 
	while(second > (clock() - start)/(double)CLOCKS_PER_SEC);
}
