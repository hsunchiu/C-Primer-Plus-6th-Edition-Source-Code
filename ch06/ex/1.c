/*
Write a program that creates an array with 26 elements and stores the 26 lowercase
letters in it. Also have it show the array contents.
*/

#include <stdio.h>

int
main(){
	int alphabets[26];
	int ch = 'a';
	
	while(ch <= 'z'){
		alphabets[ch - 'a'] = ch;
		ch ++;
	}
	
	for(ch = 'a'; ch <= 'z'; ch ++){
		printf("%c", alphabets[ch -'a']);
	}
	printf("\n");

	return 0;
}
	
