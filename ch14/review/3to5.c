/*
3. Devise a structure template that will hold the name of a month, a three-letter abbreviation for the month, the number of days in the month, and the month number.

4. Define an array of 12 structures of the sort in question 3 and initialize it for a non-leap year.

5. Write a function that, when given the month number, returns the total days in the year up to and including that month. Assume that the structure template of question 3 and an appropriate array of such structures are declared externally.
*/

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int nonumb;
};


struct month months[12] = {
	{"January", "jan", 31, 1}, 
	{"February", "feb", 28, 2}, 
	{"March", "mar", 31, 3}, 
	{"April", "apr", 30, 4}, 
	{"May", "may", 31, 5}, 
	{"June", "jun", 30, 6}, 
	{"July", "jul", 31, 7}, 
	{"August", "aug", 31, 8}, 
	{"September", "sep", 30, 9}, 
	{"October", "oct", 31, 10}, 
	{"November", "nov", 30, 11}, 
	{"December", "dec", 31, 12}
};

extern struct month months[]; 
int days(int month)
{
	int index, total;
		if (month < 1 || month > 12) 
		return(-1); /* error signal */
	else {
		for (index = 0, total = 0; index < month; index ++) total += months[index].days;
		return( total); 
	}
}
