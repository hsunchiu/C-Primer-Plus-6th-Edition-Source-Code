/*
 The s_gets() function defined in this chapter can be written using strchr() instead of a while loop to find the newline. Do so.
*/
#include <stdio.h>
#include <string.h>


char *s_gets(char *s, int n);

int
main(){
	char line[81];

	while(s_gets(line, 81) != NULL) {
		puts(line);
	}

	return 0;
}	


char *s_gets(char *s, int n){

	char *ret;
	char *find;
	
	ret = fgets(s, n, stdin);

	if(ret){
		find = strchr(s, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n'); // eat other things in the whole line buffer.
	}
	
	return ret;
}
	
