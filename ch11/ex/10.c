/*
Write a function that takes a string as an argument and removes the spaces from the string. Test it in a program that uses a loop to read lines until you enter an empty line. The program should apply the function to each input string and display the result.
*/
#include <stdio.h>

#define LEN 81

void remove_spaces(char *s);
char *s_gets(char *s, int n, FILE *stream);


int main(){
	char line[LEN];
	
	printf("Enter a line(empty line to exit):\n");

	while(s_gets(line, LEN, stdin) && line[0] !='\0') {
		remove_spaces(line);
		printf("%s", line);
		puts("");
	}
		
	return 0;
}
/* https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c */
void remove_spaces(char *s) {
	/* in place remove */
	char *d = s;
	do {
		while(*d == ' ')
			++d;
	}
	while((*s++ = *d++));
}
		
		
char *s_gets(char *s, int n, FILE *stream) {
	char *ret;

	if((ret = fgets(s, n, stream))) {
		while(*s != '\n' && *s != '\0')
			s++;
		if(*s == '\n')
			*s = '\0';
		else
			while(fgetc(stream) != '\n');	
	}

	return ret;
}
