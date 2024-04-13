#include <stdio.h>

void
smile(){
	printf("Smile!");
}

int
main(int argc, char ** argv){
	(void)argc;
	(void)argv;

	smile();
	smile();
	smile();
	printf("\n");

	smile();
	smile();
	printf("\n");

	smile();
	printf("\n");

	return 0;
}
