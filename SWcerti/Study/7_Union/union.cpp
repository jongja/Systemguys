/* UNION
 *
 * This code is union and find function
 */

#define MAX_UNION_SIZE 200000

int p[MAX_UNION_SIZE] = { 0 }; // init to '-1'
int c[MAX_UNION_SIZE] = { 0 }; // init to '1'

int find(int n) {
	if (p[n] < 0) return n;
	else {
		p[n] = find(p[n]);
		return p[n];
	}
}

int uni(int a, int b) {

	int ap = find(a);
	int bp = find(b);

	if (ap != bp) {
		p[bp] = ap;
		c[ap] += c[bp];
	}
	return c[ap];
}