#include <stdio.h>
#include <limits.h> /* For INT_MAX */
#include <float.h> /* For FLT_MAX */
#include <math.h>

int main(){
	int intmax = INT_MAX;
	float fltmax = FLT_MAX;

	printf("%d + 1 overflows to %d\n",intmax, intmax +1);
	printf("%e overflows to %e\n", fltmax, fltmax * 100.0f);	

	char *format = "%.10e %a\n";
	printf(format, FLT_MIN, FLT_MIN);
	printf(format, FLT_TRUE_MIN, FLT_TRUE_MIN);

	float f = nextafterf(1.0f, 2.0f);
	do {
		f /= 2;
		printf(format, f, f);  // print in decimal and hex for detail
	} while (f);
	return 0;
}
