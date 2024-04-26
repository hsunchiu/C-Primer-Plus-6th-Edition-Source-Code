#include <stdio.h>

inline static double square(double);
double square(double x) {
	printf("square() in %s\n", __FILE__);
	return x * x;
}

int main() {
	double q = square(1.3);


	/* try to use the square in other file */
	extern double square(double x);

	/* which square ? */
	/* in my macos clang, the square is the same inline */
	q = square(1.3);
	return 0;
}

	
