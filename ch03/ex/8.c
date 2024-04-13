#include <stdio.h>

int 
main(){
	float cups; /* we need to convert to pint, so float is better */
	printf("Please enter volume in cups: ");
	scanf("%f", &cups);
	printf("Volumes in pints: %.2f, in ounces: %.2f, in tablespoons: %.2f, in teaspoons: %.2f\n", cups /2, cups * 8, cups * 8 * 2, cups * 8 * 2 * 3);

	return 0;

}
