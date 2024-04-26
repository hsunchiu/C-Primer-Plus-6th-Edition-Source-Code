/*
Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle from the x-axis to the vector. Rectangular coordinates describe the same vector in terms of x and y components (see Figure 16.3). Write a program that reads the magnitude and angle (in degrees) of a vector and then displays the x and y components. The relevant equations are these:
x = r cos A y = r sin A
*/
#include <stdio.h>
#include <math.h>

typedef struct {
	double angle; /* degrees */
	double magnitude;
} Polar;

typedef struct {
	double x;
	double y;
} Cartesian;


Cartesian p2c(Polar polar);

int main() {
	Polar p = { .angle = 45, .magnitude = 100 };

	Cartesian c = p2c(p);

	printf("%f, %f\n",c.x, c.y); 
	
	return 0;
}


Cartesian p2c(Polar p){
	/* compound initializer */
	Cartesian c = (Cartesian){ 0.0, 0.0 };
	
	c.x = p.magnitude * cos(p.angle/180 * M_PI);
	c.y = p.magnitude * sin(p.angle/180 * M_PI);
	
	return c;
}
	
