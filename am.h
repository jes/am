/*	Header for alphametic solver	*/
/*	James Stanley 2010	*/

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* a structure for containing all information about a letter */
typedef struct {
	char	c;	/* the character	*/
	intmax_t	count;	/* number of this letter in the sum	*/
	int	min;	/* minimum value for this letter	*/
	int	value;	/* the digit assigned to this letter	*/
} Letter;

/* am.c */
void	fail(const char *fmt, ...);
int	iswhite(int c);

/* letters.c */
extern Letter	*letter;
extern int	letters;
extern intmax_t	bias;

void	add_letter(char c, intmax_t scale, int min);

/* solver.c */
extern int *value;

int	solve(void);
int	solve_letter(int n);
