/*
Write a program that opens a text file whose name is obtained interactively. Set up a loop that asks the user to enter a file position. The program then should print the part of the file starting at that position and proceed to the next newline character. Let negative or nonnumeric input terminate the user-input loop.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH 255


int main(){
	char file[MAX_PATH];
	char * find;
	long pos;
	FILE *fp;
	
	printf("Enter the file name:\n");
	
	fgets(file, MAX_PATH, stdin);

	find = strchr(file, '\n');		
	if (find)
		*find = '\0';		
	
	if ((fp = fopen(file, "r")) == NULL){
		fprintf(stderr, "Can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
		
	printf("Enter the position of the file: \n");

	while(scanf("%ld", &pos) == 1 && pos >= 0){
		if (fseek(fp, pos, SEEK_SET) == 0) {
			int ch;
			while((ch = getc(fp)) != EOF) {
				putchar(ch);
				if(ch == '\n')
					break;
			}
		}
		printf("Enter the position of the file: \n");
	}

	fclose(fp);
	printf("Done!");

	return 0;
}
