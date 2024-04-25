/*
Write a function that takes an int argument and returns the number of “on” bits in the argument. Test the function in a program.
*/

// https://en.wikipedia.org/wiki/Hamming_weight

#include <stdio.h>
#include <stdlib.h>

int popcount(int x);
int bstoi(const char *s);

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <binary>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("0b%s(%d) has %d bits in itself\n", argv[1], bstoi(argv[1]), popcount(bstoi(argv[1])));
	
	
	return 0;	
}	

int popcount(int x) {
	int count = 0;
	while(x) {
		x &= x - 1;
		count ++;
	}
	
	return count;
}

int bstoi(const char *s) {
	int ret = 0;

	while(*s) {
		ret <<= 1;
		if(*s == '1')
			ret |= 1;
	//TODO: please none '1' or '0' code	
		s++;
	}

	return ret;
} 
