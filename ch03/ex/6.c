#include <stdio.h>

int
main(){
	float quarts;
	printf("Enter the amount of water (in quarts): ");
	scanf("%f",&quarts);
	printf("Number of water molecules: %e\n",  quarts * 950 / (3.156e-23));

	return 0;
}
