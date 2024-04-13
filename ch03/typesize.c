/* typesize.c -- prints out type sizes */
#include <stdio.h>

#define printsize(type) \
do {	\
	printf("Type "#type" has a size of %u bytes\n", sizeof(type)); \
}while(0)


int main(void)
{
/* c99 provides a %zd specifier for sizes */
    printf("Type int has a size of %u bytes.\n", sizeof(int));
    printf("Type char has a size of %u bytes.\n", sizeof(char));
    printf("Type long has a size of %u bytes.\n", sizeof(long));
    printf("Type double has a size of %u bytes.\n",
            sizeof(double));


	printsize(int);
	printsize(char);
	printsize(long);
	printsize(long long);
	printsize(double);
	printsize(long double);
    return 0;
}
