/*
Write a program that takes zero command-line arguments or one command-line argument. If there is one argument, it is interpreted as the name of a file. If there is no argument, the standard input (stdin) is to be used for input. Assume that the input consists entirely of floating-point numbers. Have the program calculate and report the arithmetic mean (the average) of the input numbers.
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE * fp;
	double total = 0.0;
	double input = 0.0;
	int n = 0;
	int ret;

	if(argc > 2) {
		fprintf(stderr, "Wrong args:\n"
		"Enter a file name \n"
		"Or Enter many float numbers\n");
		
		return 1;
	}
		
	if( argc == 2 ) {
		fp = fopen(argv[1], "r");
		if (!fp){
			fprintf(stderr, "Can't of file: %s\n", argv[1]);
			return 1;
		}
	}else{
		fp = stdin;
	}
	
	do {
		ret = fscanf(fp, "%lf", &input);
		if ( ret == 1) {
			total += input;
			n++;
		}else if ( ret != EOF) {
			fprintf(stderr, "Wrong input \n");
			break;
		}
	} while(ret != EOF);

	if(n) {
		fprintf(stdout, "the arithmetic mean is %lf\n", total / n);
	}
	return 0;

}

