/*
Redo exercise 4 using a switch.
*/


#include <stdio.h>

#define STOP '#'

int
main(){
	int ch;
	while((ch = getchar()) != STOP){
		switch(ch){
			case '.':
				printf(".");
				break;
			case '!':
				printf("!!");
				break;
			default:
				printf("%c", ch);
		}	
	}

	return 0;
}
