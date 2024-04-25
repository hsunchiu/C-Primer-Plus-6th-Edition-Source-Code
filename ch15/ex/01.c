/*
Write a function that converts a binary string to a numeric value. That is, if you have
char * pbin = "01001001";
*/

#include <stdio.h>
#include <string.h>

int bstoi(const char *s) {
	int sum = 0;

	for(int len = strlen(s), i = 0; i < len; i ++) {
		sum += (1 << (len - i - 1)) * (s[i] - '0');
	}
	
	return sum;
}

int parsebinarystring(const char * string)
{
	// convert a binary string to a numeric value

	int retval = 0;
	while (*string != '\0')
	{
		retval <<= 1;
		if (*string == '1')
			retval |= 1;
		string++;
	}
	return retval;
}


int main() {
	char *pbin = "01001001";

	printf("%s is %d\n", pbin, bstoi(pbin));

	return 0;
}
