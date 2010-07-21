/*	Header for alphametic solver	*/
/*	James Stanley 2010	*/

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* am.c */
void	fail(const char *fmt, ...);
int	iswhite(int c);

/* letters.c */
extern char	*letter;
extern intmax_t	*count;
extern int	*minimum;
extern intmax_t	bias;
extern int	letters;

void	add_letter(char c, intmax_t scale, int min);

/* solver.c */
extern int *value;

int	solve(void);
int	solve_letter(int n);
int	evaluate(void);
