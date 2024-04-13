#include <stdio.h>

int main(){
	char first[255];
	char second[255];
	printf("Please enter your first name and Second name:\n");
	scanf("%s\n%s", first, second);
	printf("%s %s\n", first, second);
	printf("%s\n%s\n", first, second);
	printf("%s ", first);
	printf("%s\n", second);
	return 0;
}
