#include <stdio.h>

int
main(){
	int age;
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("About %.0f seconds has passed after you were born.\n", 3.156e7 * age);

	return 0;
}
	
