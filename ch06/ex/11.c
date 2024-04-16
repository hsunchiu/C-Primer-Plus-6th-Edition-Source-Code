/*
Write a program that reads eight integers into an array and then prints them in reverse order.
*/

#include <stdio.h>

int
main(){
	int n[8];
	int i = 0;
	printf("Please enter 8 integers: ");

	for (i = 0; i < sizeof(n) /sizeof(n[0]); i ++)
		scanf("%d", &n[i]);	

	for (i = sizeof(n) /sizeof(n[0]) - 1; i >= 0; i --)
		printf("%d ", n[i]);

	printf("\n");
}
	
