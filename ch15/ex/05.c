/*
Write a function that rotates the bits of an unsigned int by a specified number of bits to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left, and the bits lost from the left end would reappear at the right end. That is, the bit moved out of the high-order position is placed in the low-order position. Test the function in a program.
*/

#include <stdio.h>
#include <limits.h>

unsigned int rotate_l(unsigned int v, int pos){
	return  (v >> ( CHAR_BIT * sizeof(unsigned int) - pos)) | (v << pos);
} 

char * uitobs(unsigned int v, char *s){
	const static int size = CHAR_BIT * sizeof(unsigned int);
	int i;
	for(i = size - 1; i >= 0; i--, v >>= 1){
		s[i] = ( v & 01 ) + '0';
	}

	s[i] = '\0';
	return s;
}

int main() {
	char bs[CHAR_BIT * sizeof(unsigned int) + 1];
	unsigned int v;
	int pos;
	
	printf("Enter an integer: ");
	while(scanf("%u",&v) == 1){
		printf("Enter a position to left shift: ");
		while(scanf("%d", &pos) == 1){
		//TODO: handle the function
			printf("0b%s (%d) left shifted by %d is\n",uitobs(v, bs), v, pos);
			printf("0b%s\n", uitobs(rotate_l(v, pos), bs));
					
			printf("Enter a position to left shift: ");
		}

		while(getchar() != '\n');
		
		printf("Enter an integer: ");
	}

	return 0;
}
	
			
		
