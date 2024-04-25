/*
Write a program that takes as command-line arguments a character and zero or more filenames. If no arguments follow the character, have the program read the standard input. Otherwise, have it open each file in turn and report how many times the character appears in each file. The filename and the character itself should be reported along with the count. Include error-checking to see whether the number of arguments is correct and whether the files can be opened. If a file can’t be opened, have the program report that fact and go on to the next file.
*/

#include <stdio.h>
#include <stdlib.h>

int times_char(FILE *fp, int c);

int main(int argc, char *argv[]){
	int ch;
	FILE *fp;
	
	if (argc < 2) {
		fprintf(stderr, "Usage: %s character [file1 file2 ....] \n", argv[0]);
		exit(EXIT_FAILURE);
	}	

	if (argc == 2) {
		printf("There are %d %c from your input.\n", times_char(stdin, argv[1][0]), argv[1][0]);
		return 0;
	}


	for (int i = 2; i < argc; i ++) {
		if ((fp = fopen(argv[i], "r")) == NULL){
			fprintf(stderr, "Can't open %s\n", argv[i]);
			continue;
		}else{
			printf("There are %d %c in %s\n", times_char(fp, argv[1][0]), argv[1][0], argv[i]);
			(void)fclose(fp);
		}
	
	}


	return 0;
}


int times_char(FILE *fp, int c) {
	int i = 0;
	int ch;
	while((ch = getc(fp)) != EOF){
		if (c == ch) 
			i ++;
	}
	
	return i;
}




	
	
