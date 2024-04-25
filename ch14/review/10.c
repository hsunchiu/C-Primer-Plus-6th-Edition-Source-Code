/*
Suppose you have this structure:
struct gas {
	float distance;
	float gals; float mpg;
};
a. Devise a function that takes a struct gas argument. Assume that the passed structure contains the distance and gals information. Have the function calculate the correct value for the mpg member and return the now completed structure.
b. Devise a function that takes the address of a struct gas argument. Assume that the passed structure contains the distance and gals information. Have the function calculate the correct value for the mpg member and assign it to the appropriate member.
*/

#include <stdio.h>

struct gas {
	float distance;
	float gals;
	float mpg;
};

struct gas mpgs(struct gas trip) {
	trip.mpg = -1.0;
	if(trip.gals > 0)
		trip.mpg = trip.distance / trip.gals;

	return trip;
}

void set_mpgs(struct gas *ptrip) {
	if(ptrip->gals > 0)
		ptrip->mpg = ptrip->distance / ptrip->gals;
	else
		ptrip->mpg = -1.0;
}

