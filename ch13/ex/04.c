/*
Write a program that sequentially displays onscreen all the files listed in the command line. Use argc to control a loop.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int ch;

	FILE * fp;
	
	if (argc < 2){
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for(int i = 1; i < argc; i ++) {
		if((fp = fopen(argv[i], "rb")) == NULL) {
			fprintf(stderr, "Can't open %s\n", argv[i]);
			/* just skip the error file */
			continue;
		}else{
			fprintf(stdout, "Open the file %s and the contents is \n", argv[i]);
			while((ch = getc(fp)) != EOF)
				putc(ch, stdout);
			(void)fclose(fp);
		}
	}
	
	return 0;
}
