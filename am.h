/*	Header for alphametic solver	*/
/*	James Stanley 2010	*/

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* am.c */
void	fail(const char *fmt, ...);
int	iswhite(int c);

/* letters.c */
extern	char	*letter;
extern	intmax_t	*count;
extern	int	letters;

void	add_letter(char c, intmax_t scale);
