/*
6. Now modify the program of Programming Exercise 5 so that it computes the sum of the squares of the integers. (If you prefer, how much money you receive if you get $1 the first day, $4 the second day, $9 the third day, and so on. This looks like a much better deal!) C doesn’t have a squaring function, but you can use the fact that the square of n is n * n.

*/
#include <stdio.h>

int main(void)
{
	int count, sum, max_count;
	sum = 0;
	count = 1;

	printf("How many integers would you like to sum? ");
	scanf("%d", &max_count);
	while (count <= max_count)
	{
		sum = sum + count * count;
		count++;
	}
	printf("sum = %d\n", sum);

	return 0;
}
