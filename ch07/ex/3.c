/*
Write a program that reads integers until 0 is entered. After input terminates, the program should report the total number of even integers (excluding the 0) entered, the average value of the even integers, the total number of odd integers entered, and the average value of the odd integers.
*/

#include <stdio.h>

int
main(){
	int number;
	int evenno = 0;
	float evensum = 0;
	int oddno = 0;
	float oddsum = 0; 	
	do {
		printf("Enter an number(0 to quit): ");
		scanf("%d", &number);
	
		if(number % 2) { 
			oddno ++;
			oddsum += number;
		}else{
			if( number != 0){
				evenno ++;	
				evensum += number;	
			}
		}
	} while( number != 0);
	
	if ( evenno )
		printf("the number of even: %d, the average value of the evens: %f\n", evenno, evensum / evenno);

	if ( oddno) 
		printf("the number of odd: %d, the average value of the odd: %f\n", oddno, oddsum / oddno );

	return 0;
}


