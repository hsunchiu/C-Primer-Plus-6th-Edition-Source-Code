/*
Devise a program that counts the number of characters in its input up to the end of file.
*/

#include <stdio.h>

int
main(){

	int cnt = 0;
	while(getchar()!= EOF){
		cnt++;
	}
	printf("%d\n", cnt);
}
