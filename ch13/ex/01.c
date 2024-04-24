/*
Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user’s
response instead of using command-line arguments.
*/

#include <stdio.h>
#include <stdlib.h> // ANSI C exit() prototype
#include <string.h> // for strchr

#ifndef MAX_PATH 
#define MAX_PATH  255
#endif

int main(int argc, char *argv[])
{
	int ch;         // place to store each character as read
	FILE *fp;       // "file pointer" 
	long count = 0;
	
	char fname[MAX_PATH];
	
	fprintf(stdout, "Please Enter the file name: \n");

	fgets(fname, MAX_PATH, stdin);

	//fix the error, '\n' cause can't open the file
	char * find = strchr(fname, '\n');
	
	if(find) {
		*find = '\0';
	}else{
		fprintf(stderr,"Wrong path name");
		exit(EXIT_FAILURE);
	}
	
	if (( fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", fname);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch,stdout);  // same as putchar(ch);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters\n", fname, count);

	return 0;
}
