/*
Modify the program in Listing 13.5 so that it uses a command-line interface
instead of an interactive interface.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;	// fa for append file, fs for source file
	int files = 0;  // number of files appended

	if (argc < 3){
		fprintf(stderr, "Usage: %s src-file appended-file1 ...\n", argv[0]);
		exit(1);
	}

	puts("Enter name of destination file:");
	if ((fa = fopen(argv[1], "a")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(2); 
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(3);
	}

	while ((files + 2) < argc && argv[files+2][0] != '\0')
	{
	if (strcmp(argv[1], argv[files+2]) == 0)
	    fputs("Can't append file to itself\n",stderr);
	else if ((fs = fopen(argv[files+2], "r")) == NULL)
	    fprintf(stderr, "Can't open %s\n", argv[2]);
	else
	{
	    if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
	    {
		fputs("Can't create input buffer\n",stderr);
		continue;
	    }
	    append(fs, fa);
	    if (ferror(fs) != 0)
		fprintf(stderr,"Error in reading file %s.\n",
			argv[1]);
	    if (ferror(fa) != 0)
		fprintf(stderr,"Error in writing file %s.\n",
			argv[files+2]);
	    fclose(fs);
	    printf("File %s appended.\n", argv[files+2]);
	    files++;
	}
	}
	printf("Done. %d files appended.\n", files);
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; // allocate once

	while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
		fwrite(temp, sizeof (char), bytes, dest);
}
