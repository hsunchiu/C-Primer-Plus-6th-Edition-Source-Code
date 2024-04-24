/*
Write a file-copy program that takes the original filename and the copy file
from the command line. Use standard I/O and the binary mode, if possible.
*/

#include <stdio.h>
#include <stdlib.h> /* For exit flags */


int main(int argc, char *argv[]) {
	// Fix the error of binary mode
	//char ch;
	int ch;
	FILE * fsrc;
	FILE * fdest;

	if ( 3 != argc ) {
		fprintf(stderr, "Usage %s source_file destiantion_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fsrc = fopen(argv[1], "rb")) == NULL){
		fprintf(stderr, "Can;t open file %s for read\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if ((fdest = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open file %s for write\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(fsrc)) != EOF) {
		putc(ch, fdest);
	}
	
	fclose(fdest);
	fclose(fsrc);

	return 0;
}
	
	
