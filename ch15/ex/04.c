/*
Write a function that takes two int arguments: a value and a bit position. Have the function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test the function in a program.
*/

#include <stdio.h>
#include <limits.h>


int checkbit(int v, int pos) {
//	return (v & (1 << pos)) > 0;
	v >>= pos;
	return v & 01;
}


int main(void) {

	int v, pos, ch;

	printf("Enter an integer: ");

	while(scanf("%d", &v) == 1) {
		printf("Enter a postion: ");
		while(scanf("%d", &pos) == 1) {
			printf("Postion %d of %d is %d\n", pos, v, checkbit(v, pos));
			printf("Enter a postion: ");
		}
		while(getchar() != '\n');

		printf("\nEnter an integer: ");
	}

	puts("Bye.");
	return 0;
}
