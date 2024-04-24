/*
Write and test in a loop a function that returns the number of times it has been called.
*/	
#include <stdio.h>
void call_n(void);

int main(){
	for (int i = 1; i <=10; ++i ){
		call_n();
	}
	return 0;
}


void call_n(){
	static int n = 0;
	printf("%s called %d time(s)\n",__func__, ++n);
}
	
