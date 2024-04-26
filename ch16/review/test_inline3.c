#include <stdio.h>
inline double square(double x){
	printf("square() in %s\n", __FILE__);
	return (int)(x * x + 0.5);
}

void masp(double w){
	double kw = square(w);
}
