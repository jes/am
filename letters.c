/*	Letter handling for alphametic solver	*/
/*	James Stanley 2010	*/

#include "am.h"

char	*letter;
intmax_t	*count;
int	*minimum;
int	letters;

/*	Adds the given letter to the system.	*/
/*	For example, given the input "SEND", you should call:	*/
/*	  add_letter('S', 1000, 1); add_letter('E', 100, 0);	*/
/*	  add_letter('N', 10, 0); add_letter('D', 1, 0);	*/
/*	c specifies the letter, scale the amount, and min the minimum value	*/
/*	Use a negative value for scale if appropriate.	*/
/*	Returns the index to use for letter c in the letter arrays	*/
int add_letter(char c, intmax_t scale, int min) {
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
		minimum	= realloc(minimum,	sizeof(int) * letters);

		letter[i]	= c;
		count[i]	= 0;
		minimum[i]	= min;
	}

	/* now increase the count by the scale */
	count[i] += scale;

	/*	if the new minimum is greater than the old one, use it.	*/
	/*	For example, if a letter is allowed to be 0 in one place but must be	*/
	/*	at least 1 in another, then 1 is the real minimum.	*/
	if(min > minimum[i]) minimum[i] = min;

	return i;
}
