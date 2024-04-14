/* praise1.c -- uses an assortment of strings */
#include <stdio.h>
#define PRAISE "What an extraordinary being!"
int main(void)
{
    char overflow[10] = { '\0' };
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Overflow: %s\n", overflow);
  
    return 0;
}

