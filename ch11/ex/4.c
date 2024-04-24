/*
Design and test a function like that described in Programming Exercise 3 except that it accepts a second parameter specifying the maximum number of characters that can be read.
*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char *readword(char *s, int n, FILE *stream){	
	int ch;

	int in = 0;
	int i = 0;

	while((ch = fgetc(stream)) != EOF && i < n) {
		// first word store the character
		if (!isspace(ch)){
			s[i] = ch;
			++i;
			in = 1;
		}else if (in) {
			s[i] = '\0';
			in = 0;
			// clear the rest in the buffer
			while(ch != '\n')
				ch = fgetc(stream);
			break;
		}else {
			in = 0;		
		}
	}
	
	return s;			
}	

int main(){	

	char line[81];
	
	readword(line, 80, stdin);

	printf("%s\n", line);	
		
	return 0;
}

	
