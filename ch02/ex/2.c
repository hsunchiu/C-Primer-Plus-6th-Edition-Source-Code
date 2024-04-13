#include <stdio.h>

int main(){
	printf("Please inter your name and address:\n");
	char name[255];
	char address[255];

	scanf("%s\n%s", name, address);
	
	printf("%s lives at %s\n", name, address);

	return 0;
}
