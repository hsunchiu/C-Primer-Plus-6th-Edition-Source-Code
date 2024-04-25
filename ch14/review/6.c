#include <stdio.h>
#include "starfolk.h" /* make struct defs available */
void prbem (const struct bem * pbem ) {
	printf("%s %s is a %d-limbed %s.\n", pbem->title.first, pbem->title.last, pbem->limbs, pbem->type);
}
