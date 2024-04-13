#include <stdio.h>

int
main(){
	float inch = 0.0;
	printf("Enter your height in inches: ");
	scanf("%f", &inch);
	printf("height in centimeters: %.2f\n", inch * 2.54);

	return 0;
}
