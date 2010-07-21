/*	The solver code for the alphametic solver	*/
/*	James Stanley 2010	*/

#include "am.h"

int	*value;
char	taken[10];

/*	solves the alphametic from the information in the count[] and minimum[]	*/
/*	arrays, storing letter values in the value[] array, which is allocated	*/
/*	by this function.	*/
/*	returns 1 if a solution is found and 0 otherwise	*/
int solve(void) {
	/* allocate value array */
	value = malloc(sizeof(int) * letters);

	/* if more than 10 letters, there can be no solution */
	if(letters > 10) return 0;

	/* set each letter to be non-taken */
	memset(taken, 0, sizeof(taken));

	/* recursively solve letters, starting at letter 0 */
	return solve_letter(0);
}

/*	recursively solves letter n	*/
/*	returns 1 if a solution is found and 0 otherwise	*/
int solve_letter(int n) {
	int v;

	/* if we've reached the end, test this solution */
	if(n == letters) {
		if(evaluate() == 0)	return 1;
		else	return 0;
	}

	for(v = minimum[n]; v < 10; v++) {
		if(taken[v]) continue;

		taken[v] = 1;
		value[n] = v;

		if(solve_letter(n + 1)) return 1;

		taken[v] = 0;
	}

	return 0;
}

/*	evaluates the alphametic using the values specified in value[] and count[]	*/
/*	a value of 0 indicates that a solution has been found	*/
int evaluate(void) {
	int i;
	intmax_t val = bias;

	for(i = 0; i < letters; i++) {
		val += count[i] * value[i];
	}

	return val;
}
