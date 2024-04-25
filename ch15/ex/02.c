/*
Write a program that reads two binary strings as command-line arguments and prints the results of applying the ~ operator to each number and the results of applying the
&, |, and ^ operators to the pair. Show the results as binary strings. (If you don’t have a command-line environment available, have the program read the strings interactively.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* for CHAR_BIT */


int bstoi(char *s); 
char * itobs(int n, char *s);
void show_bstr(const char *s);
int bitflip(int x); 
int bitand(int x, int y);
int bitor(int x, int y);
int bitxor(int x, int y);


int main(int argc, char * argv[]) {
	char buff[CHAR_BIT * sizeof(int) + 1];
	
	int xi = 0, yi = 0;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s binary1 binary2\n" 
			"Example %s 1010 0101\n", argv[0], argv[0]);
		exit(EXIT_FAILURE);
	}
	
	xi = bstoi(argv[1]);
	yi = bstoi(argv[2]);
	
	

	
	printf("~%s = 0b%s\n", argv[1], itobs(bitflip(xi),buff)); 
	printf("~%s = 0b%s\n", argv[2], itobs(bitflip(yi),buff));
	printf("%s & %s = 0b%s\n", argv[1], argv[2], itobs(bitand(xi, yi), buff));		
	printf("%s | %s = 0b%s\n", argv[1], argv[2], itobs(bitor(xi, yi), buff));		
	printf("%s ^ %s = 0b%s\n", argv[1], argv[2], itobs(bitxor(xi, yi), buff));		
		
	
	return 0;	
	
}	

	
int bstoi(char *s) {
	int ret = 0;

	while(*s) {
		ret <<= 1;
		if(*s != '0' && *s != '1') {
			fprintf(stderr, "Error: input string is not binary.\n");
			return 0;
		}

		if(*s == '1')
			ret |= 1;	
		s++;
	}
		
	return ret;
}

char * itobs(int n, char *s) {
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	
	for(i = size - 1 ; i >= 0; i --, n >>= 1) {
		s[i] = (01 & n) + '0';
	}

	s[size] = '\0';

	return s;
}

void show_bstr(const char *s) {
	int i = 0;
	while(s[i]){
		putchar(s[i]);
		if (++i % 4 == 0 && s[i]) 
			putchar(' ');
	}
}

int bitflip(int x) {
	return ~x;
}

int bitand(int x, int y){
	return x & y;
}

int bitor(int x, int y){
	return x | y;
} 

int bitxor(int x, int y){
	return x ^ y;
}

