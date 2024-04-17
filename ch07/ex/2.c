/*
Write a program that reads input until encountering #. Have the program print each input character and its ASCII decimal code. Print eight character-code pairs per line. Suggestion: Use a character count and the modulus operator (%) to print a newline character for every eight cycles of the loop.
*/

#include <stdio.h>
#define STOP '#'
int
main(){
	int ch;
	int cnt = 0;	
	while((ch = getchar()) != STOP){
		printf("%c:%-3d", ch, ch);	
		printf((++cnt % 8) ? " " : "\n");
	}
	
	/* fix the last line with a newline */
	if ( cnt % 8 )
		printf("\n");
	
	return 0;
}
