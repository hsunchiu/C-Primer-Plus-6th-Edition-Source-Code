/*
Write a program with the following behavior. First, it asks you how many words you wish to enter. Then it has you enter the words, and then it displays the words. Use malloc() and the answer to the first question (the number of words) to create a dynamic array of the corresponding number of pointers-to-char. (Note that because each element in the array is a pointer-to-char, the pointer used to store the return value of malloc() should be a pointer-to-a-pointer-to-char.) When reading the string, the program should read the word into a temporary array of char, use malloc() to allocate enough storage to hold the word, and store the address in the array of char pointers. Then it should copy the word from the temporary array into the allocated storage. Thus, you wind up with an array of character pointers, each pointing to an object of the precise size needed to store the particular word. A sample run could look like this:
How many words do you wish to enter? 5 
Enter 5 words now:
I enjoyed doing this exerise
Here are your words:
I enjoyed doing this exercise
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 81

int main(){
	int size;
	printf("How may words do you wish to enter? ");
	while(scanf("%d", &size) == 1 && size > 0) {
		printf("Enter %d words now:\n", size); 
		char ** arr = malloc(size * sizeof(char *));
		if (arr) {
			char line[LINE];	
			int i = 0;
			// FIX: can't read the correct word Maybe blocking problem?
			while(i < size && scanf("%s",line) == 1) {
				char * s = malloc(strlen(line) * sizeof(char) + 1);
				//TODO: check the error of malloc failure.
				strcpy(s, line);
				arr[i] = s;	
				i++;
							
			} 	
	
			// eating line.
			while(getchar() != '\n');
			
			printf("Here are you words:\n");			
			// print the result and free 
			for( i = 0; i < size; i++) {
				printf("%s\n", arr[i]);
				free(arr[i]);		
			}
			// free the  arr of storing the pointer of char *
			free(arr);	
			
						
		}else{
			printf("Can't malloc. \n");
			return 1;		
		}
		
		printf("How many words do you wish to enter? "); 
	}	
	
	return 0;
}	

	
	
