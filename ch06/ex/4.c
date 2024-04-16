/*
Use nested loops to produce the following pattern:
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/
#include <stdio.h>

int
main(){
//	int i, j;
//	int sum = 0;
//	for ( i = 0; i < 6 ; i ++) {
//		for ( j = 0; j <= i; j ++ ){
//			printf("%c", 'A' + sum );
//			sum ++;
//		}
//		printf("\n");
//	}
//	return 0;
	char c = 'A';

	for (int i = 1; i < 7; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("%c", c++); // print and THEN increment c
		}
		printf("\n");
	}

	return 0;
}		
