/*
The s_gets() function defined in this chapter can be written in pointer notation instead of array notation so as to eliminate the variable i. Do so.
*/
#include <stdio.h>

char * s_gets(char *s, int n){
	char * ret;
	
	ret = fgets(s, n, stdin);
	
	if(ret){
		while(*s != '\n' && *s != '\0')
			s++;
		if(*s == '\n')
			*s = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret;
}
