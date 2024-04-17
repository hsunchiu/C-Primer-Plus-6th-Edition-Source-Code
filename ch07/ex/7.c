/*
Write a program that requests the hours worked in a week and then prints the gross pay, the taxes, and the net pay. Assume the following:
a. Basic pay rate = $10.00/hr
b. Overtime (in excess of 40 hours) = time and a half c. Tax rate: #15% of the first $300
20% of the next $150
25% of the rest
Use #define constants, and don’t worry if the example does not conform to current tax law.
*/

#include <stdio.h>

#define BASIC_RATE 10.0
#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLIER 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25

float gross(float hours);
float tax(float gross_salary);

int
main(){
	float hours = 0.0;
	
	printf("Enter the hours you work in a week: ");
	scanf("%f", &hours);

	float gross_salary = gross(hours);
	float t = tax(gross_salary);
	
	printf("Gross: %f, Tax:%f, Net:%f\n", gross_salary, t, gross_salary -t );
	return 0;
}	

float
gross(float hours){
	float gross = 0.0;
	if (hours > OVERTIME_HOURS ){
		gross = BASIC_RATE * OVERTIME_HOURS + (hours - OVERTIME_HOURS) * BASIC_RATE * OVERTIME_MULTIPLIER;
	}else{
		gross = BASIC_RATE * hours;
	}
	return gross;
}


float tax(float gross_salary){
	float tax;
	if ( gross_salary <= TAX_BRACKET_1 )
		tax = gross_salary  * TAX_RATE_1;
	else if( gross_salary <= TAX_BRACKET_2 )
		tax = TAX_BRACKET_1 * TAX_RATE_1 + (gross_salary - TAX_BRACKET_1 ) * TAX_RATE_2;
	else
		tax = TAX_BRACKET_1 * TAX_RATE_1 + (TAX_BRACKET_2 - TAX_BRACKET_1 ) * TAX_RATE_2 + (gross_salary - TAX_BRACKET_2) * TAX_RATE_3;
	return tax;
}

