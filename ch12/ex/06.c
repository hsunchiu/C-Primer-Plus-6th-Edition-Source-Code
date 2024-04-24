/*Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or print the numbers, but do print how many times each number was produced. Have the program do this for 10 different seed values. Do the numbers appear in equal amounts? You can use the functions from this chapter or the ANSI C rand() and srand() functions, which follow the same format that our functions do. This is one way to examine the randomness of a particular random-number generator.*/

#include <stdio.h>
#include <stdlib.h>
#ifndef NDEBUG
#include <time.h>
#endif

int random1to10(void);

int main(){
	int times[10];

#ifndef NDEBUG
	srand(time(0));
#endif
	
	for(int i = 0; i < (sizeof(times) / sizeof(*times)); i ++){
		times[i] = 0;
	}
	
	for(int i = 0; i < 1000; i ++) {
		times[random1to10() - 1] ++;
	}

	printf("number         times\n");
	
	for(int i = 0; i < (sizeof(times) /sizeof(*times)); i++) {
		printf("%-10d%-10d\n", i + 1, times[i]);
	}

}

int random1to10(void){
	return rand() % 10 + 1;
}
	
	
	
