/*
Modify Listing 16.17 so that it uses an array of struct names elements (as defined after the listing) instead of an array of double. Use fewer elements, and initialize the array explicitly to a suitable selection of names.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5

struct names{
	char first[10];
	char last[10];
};


int compare(const void *, const void*);
void show_info(const struct names *, int);


int main() {

	/* https://www.behindthename.com/random/ */
	struct names narray[NUM] = { 	[0] = { "Willehelm", "Chen"},
				     	[1] = { "Emoke", "Chambers"},
					[2] = { "Nadira", "Vivas" },
					[3] = { "Dylan", "Apostolova" },
					[4] = { "Rosa", "Munro" },
					};
	
	puts("Before Qsort:\n");
	show_info(narray, NUM);
	puts("");

	puts("Ater Qsort:\n");
	qsort(narray,NUM, sizeof(struct names), compare);
	show_info(narray, NUM);	
	puts("");	

	return 0;
}

void show_info(const struct names ar[], int n) {
		for (int i = 0; i < n; ++i) {
			printf("%s %s\n", ar[i].first, ar[i].last);
		}
}
	




int compare(const void * p1,const void *p2) {
	int ret;
	struct names * a1 = (struct names *) p1;
	struct names * a2 = (struct names *) p2;
	
	ret = strcmp(a1->first, a2->first);
	
	if(ret)
		return ret;
	
	return strcmp(a1->last, a2->last);	
}
