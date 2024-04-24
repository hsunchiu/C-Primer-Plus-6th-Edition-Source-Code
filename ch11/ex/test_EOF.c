#include <stdio.h>

int
main(){
	int ch;
	while((ch = getchar()) != EOF){
		putchar(ch);	
	}

	if ( ch == EOF) {
		printf("\n");
		printf("EOF is %d\n", ch);
	}	
	

	return 0;
}
