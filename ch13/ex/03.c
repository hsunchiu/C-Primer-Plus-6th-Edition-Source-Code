/*
Write a file copy program that prompts the user to enter the name of a text file to act as the source file and the name of an output file. The program should use the toupper() function from ctype.h to convert all text to uppercase as it’s written to the output file. Use standard I/O and the text mode.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int ch;

	FILE *fpsrc;
	FILE *fpdest;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s src-file dest-file \n", argv[0]);
		exit(EXIT_FAILURE);
	}	
	
	if (!strcmp(argv[1], argv[2])){
		fprintf(stderr, "src-file should not be same as dest-file.\n");
		exit(EXIT_FAILURE);
	}
	
	if ((fpsrc = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Can't open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fpdest = fopen(argv[2], "w")) == NULL){
		fprintf(stderr, "Can't open file: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(fpsrc)) != EOF){
		if (isalpha(ch))
			putc(toupper(ch), fpdest);
		else
			putc(ch, fpdest);
	}	



	(void)fclose(fpsrc);
	(void)fclose(fpdest);

	return 0;
}
	
