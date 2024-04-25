/*
Create a text file consisting of 20 rows of 30 integers. The integers should be in the range 0–9 and be separated by spaces. The file is a digital representation of a picture, with
the values 0 through 9 representing increasing levels of darkness. Write a program that reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward converting this digital representation to a picture, have the program use the values
in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a space character, a 1 value to the period character, and so on, with each larger number represented by a character that occupies more space. For example, you might use # to represent 9. The last character (the 31st) in each row should be a null character, making it an array of 20 strings. Have the program display the resulting picture (that is, print the strings) and also store the result in a text file. For example, suppose you start with this data:


For one particular choice of output characters, the output looks like this:


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* number 7 is not defined in the question, I pick up ^ as 7 */
static const char table[10] = {' ', '.' , '\'', ':', '~', '*', '=', '^', '%', '#'};
#define COL 30
#define ROW 20

char convert(int n);

int main(int argc, char *argv[]) {
	int digit[ROW][COL];
	char picture[ROW][COL+1];
	FILE *fpin = NULL;
	FILE *fpout = NULL;
	
	if (argc != 3){
		fprintf(stderr, "Usage: %s <digit-file> <image-file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fpin = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE); 
	}
	
	if (strcmp(argv[1], argv[2]) == 0){
		fprintf(stderr, "digit-file should not be same as image-file\n");
		exit(EXIT_FAILURE); // Maybe need to close fpin
	}
	
	/* read all the data to digit */
	for (int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++) {
			if(fscanf(fpin, "%d", *(digit + i) + j) != 1){
				fprintf(stderr, "Valid data\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	(void)fclose(fpin);

	/* convert the data to picture mode */
	for (int i =0; i < ROW; i++){
		int j;
		for(j = 0; j < COL; j++){
			picture[i][j] = convert(digit[i][j]);
		}
		/* append '\0' for each line */
		picture[i][j] = '\0';	
	}
			

	if ((fpout = fopen(argv[2], "w")) == NULL){
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE); // Maybe need to close fpin
	}
	
	// save the picture
	
	for(int i = 0; i < ROW; i++){
			puts(*(picture+i));
			fprintf(fpout, "%s\n", *(picture+i));
	}	
	(void)fclose(fpout);

	
	return 0;

}

char convert(int n){
	return table[n];
}
