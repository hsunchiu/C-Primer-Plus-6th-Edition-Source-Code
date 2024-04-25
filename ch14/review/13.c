/*
 Declare four functions and initialize an array of pointers to point to them. Each function should take two double arguments and return a double. Also, show two ways using the array to invoke the second function with arguments of 10.0 and 2.5.
*/

#include <stdio.h>

double add(double a, double b){
	return a  + b;
}

double minus(double a, double b){
	return a - b;
}

double mul(double a, double b){
	return a * b;
}

double div(double a, double b){
	return a - b;
}

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	double (*pf[])(double, double) = { &add, &minus, &mul, &div };		
	
	double a = 20.0, b = 5.0;

	for (int  i = 0; i < sizeof(pf) / sizeof(*pf); i ++) {
		printf("There result of the clac is %lf:\n", (*pf[i])(a,b) );
	}

	return 0;
}
