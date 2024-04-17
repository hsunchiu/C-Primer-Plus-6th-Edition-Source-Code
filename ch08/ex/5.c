/*
Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing strategy. For example, have the program initially guess 50, and have it ask the user whether the guess is high, low, or correct. If, say, the guess is low, have the next guess be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be halfway between 75 and 50, and so on. Using this binary search strategy, the program quickly zeros in on the correct answer, at least if the user does not cheat.
*/

#include <stdio.h>

int
main(){
	int upper = 10;
	int lower = 0;
	int guess = 50;

	char ch;
	
	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right, with a h if it's");
	printf("\ntoo high and an l if it's too low.\n");
	printf("Uh...is your number %d?\n", guess);
	
	while((ch=getchar()) != 'y'){
		while(getchar() != '\n')
			continue;

		if(ch == 'h')
			upper = guess;
		else if (ch == 'l')
			lower = guess;
		else {
			printf("Invalid input. Try again!\n");
			continue;
		}
		guess = ( upper + lower ) / 2;
		printf("Well, then, it it %d?\n", guess);
	}

	printf("Done!\n");

	return 0;
}
