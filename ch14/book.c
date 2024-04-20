/* book.c -- one-book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL  41      /* maximum length of title + 1         */
#define MAXAUTL  31      /* maximum length of author's name + 1 */

char * s_gets(char *s , int n);

struct book {            /* structure template: tag is book     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};                       /* end of structure template           */

int main(void)
{
    struct book library; /* declare library as a book variable  */
    
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL); /* access to the title portion         */
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n",library.title,
          library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author,
          library.title, library.value);
    printf("Done.\n");
          
    return 0;
}

char *s_gets(char *s, int n){
	char * ret;
	char * find;
	
	ret = fgets(s, n, stdin);
	if (ret){
		find = strchr(s, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return ret;
}

