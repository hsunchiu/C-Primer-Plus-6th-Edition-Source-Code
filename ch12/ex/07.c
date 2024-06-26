// Write a program that behaves like the modification of Listing 12.13, which
// we discussed after showing the output of Listing 12.13. That is, have the
// program produce output like the following:
//     > Enter the number of sets; enter q to stop: 18
//     > How many sides and how many dice? 6 3
//     > Here are 18 sets of 3 6-sided throws.
//     > 12 10  6  9  8 14  8 15  9 14 12 17 11  7 10
//       13  8 14
//     > How many sets? Enter q to stop: q


#include <stdio.h>
#include <stdlib.h>

static int rolldie(int sides)
{
	// roll one n-sided die and return outcome

	return rand() % sides + 1;
}

int rolldice(int dice, int sides)
{
	// roll multiple n-sided dice and return outcome

	int total = 0;

	for (int i = 0; i < dice; i++)
		total += rolldie(sides);

	return total;
}

void dicerolls(int sets, int dice, int sides)
{
	// roll multiple sets of multiple n-sided dice and print results

	printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
	for (int i = 0; i < sets; i++)
		printf("%2d ", rolldice(dice, sides));
	putchar('\n');
}

void clear_input_stream(void)
{
        while (getchar() != '\n')
                continue;
}

int main(void)
{
	int sets, dice, sides;

	puts("Enter the number of sets; enter q to stop.");
	while (scanf("%d", &sets) == 1 && sets > 0)
	{
		dice = sides = -1;
		printf("How many sides and how many dice? ");
		scanf("%d %d", &sides, &dice);
		while (dice < 0 || sides < 0)
		{
			clear_input_stream();
			puts("Invalid input. Positive integers only.");
			puts("How many sides and how many dice? ");
			scanf("%d %d", &sides, &dice);
		}

		dicerolls(sets, dice, sides);

		puts("How many sets? Enter q to stop.");
	}

	return 0;
}

