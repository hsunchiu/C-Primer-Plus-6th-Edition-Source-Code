/* showf_pt.c -- displays float value in two ways */
#include <stdio.h>
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
  
    printf("%f can be written %e\n", aboat, aboat);
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
	printf("And it's %a in hexadicial, power of 2 notaion\n", aboat);
#endif
    printf("%f can be written %e\n", abet, abet);
    printf("%f can be written %e\n", dip, dip);
   
    return 0;
}
