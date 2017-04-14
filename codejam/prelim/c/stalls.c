#include <stdio.h>
#include <stdlib.h>

int main (void) {
	
	int i, j, T;
	long n, k, l, r, p;
	long less;
	scanf("%d ", &T);

	for (i = 0; i < T; i++) {
		scanf("%ld %ld ", &n, &k);

		// Every stall is occupied, print two zeroes
		if (n == k) {
			printf("Case #%d: 0 0\n", i+1);
			continue;
		}
		
		// If only one person enters, we have a solution
		if (k == 1) {
			printf("Case #%d: %ld %ld\n", i+1, n/2, (n-1)/2);
			continue;
		}

		long left = (n-1)/2;
		long right = n/2;
		long l_count = 1, r_count = 1;
		p = 4;
		long l1c, l2c, r1c, r2c;
		long l1, l2, r1, r2;

		while (p <= k) {
			l1 = (left-1)/2;
			r1 = left / 2;
			l2 = (right-1)/2;
			r2 = right/2;

			l1c = l_count;
			r1c = l_count;
			l2c = r_count;
			r2c = r_count;

			l_count = 0; r_count = 0;
			left = (l1 < l2 ? l1 : l2);
			right = (r1 > r2 ? r1 : r2);

			l_count = (l1 == left ? l1c : 0) + (r1 == left ? r1c : 0) + (l2 == left ? l2c : 0) 
					  + (r2 == left ? r2c : 0);
			r_count = (l1 > left ? l1c : 0) + (r1 > left ? r1c : 0) + (l2 > left ? l2c : 0) 
					  + (r2 > left ? r2c : 0);
			p *= 2;
		}


		long rem = k - ((p/2)-1);
		if (rem <= r_count) {
			l = (right-1)/2;
			r = right/2;
		} else {
			l = (left-1)/2;
			r = left/2;
		}

		printf("Case #%d: %ld %ld\n", i+1, r, l);
	}

	return 0;
}
