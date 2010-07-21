/*	Letter handling for alphametic solver	*/
/*	James Stanley 2010	*/

#include "am.h"

char	*letter;
intmax_t	*count;
int	letters;

/*	Adds the given letter to the system.	*/
/*	For example, given the input "SEND", you should call:	*/
/*	  add_letter('S', 1000); add_letter('E', 100);	*/
/*	  add_letter('N', 10); add_letter('D', 1);	*/
/*	Use a negative value for scale if appropriate.	*/
void add_letter(char c, intmax_t scale) {
	int i;

	/* try to find c in the "letter" array */
	for(i = 0; i < letters; i++) {
		if(letter[i] == c) break;
	}

	/* c was not found in the array, extend arrays and add the letter */
	if(i == letters) {
		letters++;
		letter	= realloc(letter,	letters);
		count	= realloc(count,	sizeof(intmax_t) * letters);

		letter[i]	= c;
		count[i]	= 0;
	}

	/* now increase the count by the scale */
	count[i] += scale;
}
