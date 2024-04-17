/*
Write a program that accepts a positive integer as input and then displays all the prime numbers smaller than or equal to that number.
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int
main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	for(int i=1; i <= n; i++) {
		if (isPrime(i))
			printf("%d ", i);
	}
	printf("\n");
		
	return 0;
}

bool
isPrime(int n){
	for(int i = 2; i < n; i++){
		if (n % i == 0)
			return false;
	}
	return true;
}
