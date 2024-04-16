/*
Use nested loops to produce the following pattern:
F
FE
FED
FEDC
FEDCB
FEDCBA
Note: If your system doesn’t use ASCII or some other code that encodes letters in numeric order, you can use the following to initialize a character array to the letters of the alphabet:
char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
Then you can use the array index to select individual letters; for example, lets[0] is
'A', and so on.

*/
#include <stdio.h>

int
main(){
	int i, j;
	for ( i = 0; i <= 'F' - 'A'; i ++) {
		for( j = 0; j <= i; j ++){
			printf("%c",  'F' - j);
		}
		printf("\n");
	}	
	return 0;
}
