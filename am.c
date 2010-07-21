/*	Alphametic solver	*/
/*	Usage: am SEND + MORE = MONEY	*/
/*	James Stanley 2010	*/

#include "am.h"

/*	causes the given message to be printed on stderr	*/
/*	the program terminates with exit(1);	*/
void fail(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(1);
}

/*	return 1 if c is space, tab, line feed, or carriage return	*/
/*	return 0 otherwise	*/
int iswhite(int c) {
	if(c == ' ' || c == '\t' || c == '\n' || c == '\r') return 1;
	else return 0;
}

int main(int argc, char **argv) {
	int	i;
	int	k = 1, k1 = 1;
	intmax_t	scale;
	intmax_t	bias = 0;
	char	*start, *stop;
	char	*p;

	/* read the letters from the arguments */
	for(i = 1; i < argc; i++) {
		start = argv[i];

		/* use up all characters in this argument */
		while(*start) {
			/* skip whitespace */
			while(iswhite(*start)) start++;

			/* read a word */
			for(stop = start; isalpha(*stop) || isdigit(*stop); stop++);

			/* no word was read */
		  if(start == stop) {
				switch(*start) {
				case '\0':	break;
				case '+': k = 1;	break;
				case '-': k = -1;	break;
				case '=':
					if(k1 == -1) fail("Can only have one `=' sign.\n");
					else k1 = -1;
					break;
				default: fail("Unrecognised character: `%c'.\n", *start);
				}

				/* move on one character */
				start++;
				continue;
			}

			/* there is a word in [start, stop), add all letters */
			for(p = stop - 1, scale = 1; p >= start; p--, scale *= 10) {
				if(isdigit(*p))	bias += k * k1 * scale * (*p - '0');
				else	add_letter(*p, (k * k1 * scale), (p == start));
			}

			/* start at where we finished for next time */
			start = stop;
		}
	}

	return 0;
}
