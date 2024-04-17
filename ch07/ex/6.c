/*

Write a program that reads input up to # and reports the number of times that the
sequence ei occurs.
Note
The program will have to “remember” the preceding character as well as the current character. Test it with input such as “Receive your eieio award.”
*/

#include <stdio.h>

#define STOP '#'

int
main(){
	int ei_no = 0;
	int prech = STOP;	
	int ch;
	while((ch = getchar()) != STOP){
		if ('i' == ch && 'e' == prech)
			ei_no ++;
		prech = ch;
	}
	printf("%d ei occurs \n", ei_no);
	
	return 0;
}
			


