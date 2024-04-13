#include <stdio.h>

int
main(){
	float f;
	printf("Enter a floating-point value: __.__\b\b\b\b\b");
	scanf("%f", &f);
	printf("fixed-point notation: %2.6f\n", f);
	printf("exponential notation: %e\n", f);
#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 199901L
	printf("p notation: %a\n", f);
#endif

	return 0;
}

