/*
The strlen() function takes a pointer to a string as an argument and returns the length of the string. Write your own version of this function.
*/

int strlen(const char *s){
	int i = 0;
	while(*s++)
		i++;
	return i;
}
