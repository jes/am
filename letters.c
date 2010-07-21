/*	Letter handling for alphametic solver	*/
/*	James Stanley 2010	*/

#include "am.h"

Letter	*letter;
int	letters;
intmax_t	bias;

/*	Adds the given letter to the system.	*/
/*	For example, given the input "SEND", you should call:	*/
/*	  add_letter('S', 1000, 1); add_letter('E', 100, 0);	*/
/*	  add_letter('N', 10, 0); add_letter('D', 1, 0);	*/
/*	c specifies the letter, scale the amount, and min the minimum value	*/
/*	Use a negative value for scale if appropriate.	*/
void add_letter(char c, intmax_t scale, int min) {
	int i;

	/* if it's a digit, adjust the bias */
	if(isdigit(c)) {
		bias += scale * (c - '0');
		return;
	}

	/* try to find the letter c */
	for(i = 0; i < letters; i++) {
		if(letter[i].c == c) break;
	}

	/* c was not found, extend array and add the letter */
	if(i == letters) {
		letters++;
		letter	= realloc(letter,	letters * sizeof(Letter));

		letter[i].c	= c;
		letter[i].count	= 0;
		letter[i].min	= min;
		letter[i].value	= 0;
	}

	/* now increase the count by the scale */
	letter[i].count += scale;

	/*	if the new minimum is greater than the old one, use it.	*/
	/*	For example, if a letter is allowed to be 0 in one place but must be	*/
	/*	at least 1 in another, then 1 is the real minimum.	*/
	if(min > letter[i].min) letter[i].min = min;

	return;
}
