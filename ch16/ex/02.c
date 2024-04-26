/*
The harmonic mean of two numbers is obtained by taking the inverses of the two numbers, averaging them, and taking the inverse of the result. Use a #define directive to define a macro “function” that performs this operation. Write a simple program that tests the macro.
*/

#include <stdio.h>
#include <assert.h>


/* GNU and Clang extension: statement expression */
#define HARMONIC_MEAN(x, y) \
({	\
assert(x); assert(y); \
1.0f * ( 1.0 / x + 1.0 / y); \
})



int main(){
	printf("the harmonic mean of %f , %f is %f\n", 1.0, 2.0, HARMONIC_MEAN(1.0, 2.0));
	
	return 0;
}
