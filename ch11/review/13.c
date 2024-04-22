/*

*/
#include <stdio.h>
#include <string.h>   /* declares strcmp() */
#include <ctype.h>

#define ANSWER "Grant"
#define MAX 40

void upper_str(char *s);
char *s_gets(char *s, int n);

int main(void)
{
    char try[MAX];

    puts("Who is buried in Grant's tomb?");
  	s_gets(try, MAX);
/*	upper_str(try); */

	// uppercase the first character	
	if (*try != '\0')
		*try = toupper(*try);
	
    while (strcmp(try,ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
	s_gets(try, MAX);
	//upper_str(try);
	if (*try !='\0')
		*try = toupper(*try);
    }
    puts("That's right!");
    
    return 0;
}

void upper_str(char *s){
	while(*s) {
		*s = toupper(*s);
		s++;
	}
}


char *s_gets(char *s, int n){
	char * ret;
	
	if((ret=fgets(s, n, stdin))){
		while(*s != '\n' && *s != '\0')
			s ++;
		if(*s == '\n')
			*s = '\0';
		else
			while(getchar() != '\n');
	}

	return ret;

}

