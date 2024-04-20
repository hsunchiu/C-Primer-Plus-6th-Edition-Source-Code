/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>

char* s_gets(char *s, int n);

#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
                          && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
        printf("Enter the next title.\n");
    }
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
    }
    else
    	printf("No books? Too bad.\n");
    
    return 0;
}

char * s_gets(char *s, int n){
	char * ret;
	char * find;
	
	ret = fgets(s, n, stdin);
	if (ret){
		find = strchr(s, '\n');
		if (find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret;
}
