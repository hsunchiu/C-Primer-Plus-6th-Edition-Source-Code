/*
Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it offer the user a menu with five choices: print the original list of strings, print the strings in ASCII collating sequence, print the strings in order of increasing length, print the strings in order of the length of the first word in the string, and quit. Have the menu recycle until the user enters the quit request. The program, of course, should actually perform the promised tasks.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* the max line size */
#define SIZE 81
#define LIM	5


char *s_gets(char *s, int n);
char get_choice();
void ststr(char *strings[], int num, int (*compare)(const char *,const char *));
void show(char *strings[], int n);
int sort_length(const char *s1, const char *s2);
int first_word(const char *s1, const char *s2);

int main(){
	char input[LIM][SIZE];
	char *ptstr[LIM];

	int ct = 0;
	int k;

	printf("Input up to %d line, and I will sort them them. \n", LIM);
	printf("To stop, press the Enter key at a line's start.\n");

	while(ct < LIM && s_gets(input[ct], SIZE) != NULL
		&& input[ct][0] != '\0'){
		
		ptstr[ct] = input[ct];
		ct++;
	}
	

	char choice;
	do {	
	
		choice = get_choice();

		switch(choice) {
			case 'o':
			show(ptstr, LIM);		
			break;	
			case 'a':
			ststr(ptstr, LIM, strcmp); 
			show(ptstr, LIM);
			break;	
			case 'l':
			ststr(ptstr, LIM, sort_length); 
			show(ptstr, LIM);
			break;	
			case 'f':
			ststr(ptstr, LIM, first_word); 
			show(ptstr, LIM);
			break;	
			case 'q':
			break;
			default:
			break;
		
		}
	}while( choice != 'q');	

	
	return 0;

}



char get_choice() {
	puts("Choose an option:");
	puts("(o) Print strings in original order.");
	puts("(a) Print strings in ASCII collating sequence.");
	puts("(l) Print strings ordered by length.");
	puts("(f) Print strings ordered by length of the first word.");
	puts("(q) Quit.");
	puts("");
	printf("Enter a character: ");
	
	char ch = getchar();
	while(getchar() != '\n')
		continue;

	while(!strchr("oalfq", ch)){
		printf("Please sespond with o,a,l,f,q\n");
	}

	return ch;
}	
	
	


char * s_gets(char *s, int n){
	char *ret;
	char *find;	
	if((ret = fgets(s, n, stdin))){
		find = strchr(s, '\n');	
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n');
	}
	
	return ret;
}
				
void show(char *strings[], int n) {
	for (int i = 0; i < n; i ++ ) {
		printf("%s", strings[i]);
		printf("\n");
	}
}

void ststr(char *strings[], int n, int (*compare) (const char *, const char *)) {
	char * tmp;
	/* buble sort */
	for (int i = 0; i < n - 1; i ++ ){
		for(int j = 0; j < n - 1 - i; j++) {
			if ((*compare)(strings[j], strings[j+1]) > 0) {
				tmp = strings[j];
				strings[j] = strings[j+1];
				strings[j+1] = tmp;
			}
		}
	}
}

int sort_length(const char *s1, const char *s2){
	return strlen(s1) - strlen(s2);
}

int fwlen(const char * string) {
	// return length of first word of string

	int length = 0;

	// skip leading whitespace
	while (isspace(*string))
		string++;

	// count first word length
	while(!isspace(*string))
	{
		length++;
		string++;
	}

	return length;
}



int first_word(const char *s1, const char*s2){
	return fwlen(s1) - fwlen(s2);
}	

