/*	The solver code for the alphametic solver	*/
/*	James Stanley 2010	*/

#include "am.h"

char	taken[10];
intmax_t	total;

/*	returns 1 if a solution is found and 0 otherwise	*/
/*	stores values for the letters in letter[x].value	*/
int solve(void) {
	/* if more than 10 letters, there can be no solution */
	if(letters > 10) return 0;

	/* set each letter to be non-taken */
	memset(taken, 0, sizeof(taken));

	total = bias;

	/* recursively solve letters, starting at letter 0 */
	return solve_letter(0);
}

/*	recursively solves letter n	*/
/*	returns 1 if a solution is found and 0 otherwise	*/
int solve_letter(int n) {
	int v;

	/* if we've reached the end, test this solution */
	if(n == letters) {
		if(total == 0)	return 1;
		else	return 0;
	}

	for(v = letter[n].min; v < 10; v++) {
		if(taken[v]) continue;

		letter[n].value = v;

		taken[v] = 1;
		total += v * letter[n].count;

		if(solve_letter(n + 1)) return 1;

		total -= v * letter[n].count;
		taken[v] = 0;
	}

	return 0;
}
