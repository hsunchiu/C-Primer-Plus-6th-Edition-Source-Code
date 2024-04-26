#include <stdio.h>
double square(double x) {
	printf("square() in %s\n", __FILE__);

	return (int)(x * x);
}

void span(double v) {
	double kv = square(v);
}
