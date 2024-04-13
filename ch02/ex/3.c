#include <stdio.h>
#include <stdlib.h>

int main(){
	int age;
	printf("Please enter your age:");
	scanf("%d", &age);
	printf("Days: %d\n", 365 * age);

	return 0;
}
