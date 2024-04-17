/*
Write a function that takes three arguments: a character and two integers. The character is to be printed. The first integer specifies the number of times that the character is to be printed on a line, and the second integer specifies the number of lines that are to be printed. Write a program that makes use of this function.
*/

#include <stdio.h>

void chline(char, int, int);

int
main(){
	int i, j;
	char ch;

	printf("Enter the charater, row and column: ");
	
	while(scanf("%c%d%d", &ch,&i, &j) == 3) {
		chline(ch, i, j);
		// eat the rest 
		while(getchar() != '\n')
			continue;	
		
		printf("Enter the charater, row and column: ");
	}
	

	return 0;
}	


void
chline(char ch, int i, int j){
	for (int m = 0; m < i; m++){
		for (int n = 0; n < j; n++){
			putchar(ch);
		}
		putchar('\n');
	}
}	
