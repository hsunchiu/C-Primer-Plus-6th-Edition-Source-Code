/*
Modify assumption a. in exercise 7 so that the program presents a menu of pay rates from which to choose. Use a switch to select the pay rate. The beginning of a run should look something like this:
***************************************************************** Enter the number corresponding to the desired pay rate or action: 1) $8.75/hr 2) $9.33/hr
3) $10.00/hr 4) $11.20/hr
5) quit *****************************************************************
If choices 1 through 4 are selected, the program should request the hours worked. The program should recycle until 5 is entered. If something other than choices 1 through 5 is entered, the program should remind the user what the proper choices are and then recycle. Use #defined constants for the various earning rates and tax rates.
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

float gross(float basic, float hours);
float tax(float gross_salary);
void menu();
float parse_menu(int select);

int
main(){
	int select;
	float hours;
	float salary_rate;
	
	menu();
	while((scanf("%d", &select) ==1) && select != 5 ){
	
		salary_rate = parse_menu(select);	
		printf("Enter the hours you work in a week: ");
		scanf("%f", &hours);
		float gross_salary = gross(salary_rate, hours);
		float t = tax(gross_salary);
	
		printf("Gross: %f, Tax:%f, Net:%f\n", gross_salary, t, gross_salary -t );
		menu();
	}	
	return 0;
}	

void
menu(){
	printf(
		"***************************************************************** \n"
		"enter the number corresponding to the desired pay rate or action: \n"
		"  1) $8.75/hr  2) $9.33/hr					   \n"
		"  3) $10.00/hr 4) $11.20/hr					   \n"
		"  5) quit 							   \n"
		"***************************************************************** \n"
	);
}

float parse_menu(int select){
	float rate = 10.00;
	switch(select){
		case 1:
			rate = 8.75;
			break;
		case 2:
			rate = 9.33;
			break;
		case 3:	
			rate = 10.00;
			break;
		case 4: 
			rate = 11.20;	
			break;
		default:
			rate = 10.00;
	} 
	return rate;
} 

float
gross(float basic, float hours){
	float gross = 0.0;
	if (hours > OVERTIME_HOURS ){
		gross = basic * OVERTIME_HOURS + (hours - OVERTIME_HOURS) * basic * OVERTIME_MULTIPLIER;
	}else{
		gross = basic * hours;
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


