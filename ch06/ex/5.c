/*
Have a program request the user to enter an uppercase letter. Use nested loops to produce a pyramid pattern like this:

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

The pattern should extend to the character entered. For example, the preceding pattern would result from an input value of E. Hint: Use an outer loop to handle the rows. Use three inner loops in a row, one to handle the spaces, one for printing letters in ascending order, and one for printing letters in descending order. If your system doesn’t use ASCII or a similar system that represents letters in strict number order, see the suggestion in programming exercise 3.
*/
#include <stdio.h>

void printspace(int i);

int
main(){
	int l = 0;
	char ch;	
	printf("Please enter a capital character: ");
	scanf("%c", &ch);

	l = ch - 'A' + 1;
	for ( int i = 1; i <= l ; i ++){
		printspace(l - i); /* print the space for the line */
		for (int j=1; j <= 2*i - 1; j++){ /* how mamy chars in line */
			if (j <= (2*i -1) /2 + 1)
				printf("%c",'A' + j - 1); 		
			if (j > (2*i -1) / 2 + 1)
				//printf("%c", 'A' + (2 * i -1 ) / 2 - (j - ((2 * i -1 )/2)) + 1);
				printf("%c", 'A' + 2*i -j -1);
		}	
		printf("\n");	
	}

	return 0;
}

void printspace(int i){
	while(i-- > 0){
		printf(" ");
	}
}
	
