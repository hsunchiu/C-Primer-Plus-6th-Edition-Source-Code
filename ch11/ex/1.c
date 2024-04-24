/*
Design and test a function that fetches the next n characters from input (including blanks, tabs, and newlines), storing the results in an array whose address is passed as an argument.
*/

#include <stdio.h>

char *getnch(char *s, int n, FILE *stream);

int main(){
	char line[81];
	printf("Enter: \n");
	
	getnch(line, 80, stdin);

	printf("%s\n", line);
}	

char *getnch(char *s, int n, FILE * stream){
	char ch;	 
	for(int i = 0; i < n; ++i) {
		if ((ch = getc(stream)) != EOF){
			s[i] = ch;
		}else{
		 	break;
		}
	}
	return s; 
}
		
	
