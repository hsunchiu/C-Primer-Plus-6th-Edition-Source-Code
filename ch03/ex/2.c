#include <stdio.h>

int
main(){
	int ascii;	
	printf("Please enter an ascii code in decimial format: ___\b\b\b");
	scanf("%d", &ascii);
	printf("The ascii code %d is %c.\n", ascii, ascii);
	return 0;
}
	
