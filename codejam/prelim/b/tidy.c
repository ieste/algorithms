#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int i, j, k, T, first;
	long n, cpy, div;
	long digits[19];

	scanf("%d ", &T);

	for (i = 0; i < T; i++) {
		scanf("%ld ", &n);

		div = 1000000000000000000;
		cpy = n;
		first = -1;

		for (j = 0; j < 19; j++) {
			digits[j] = cpy/div;
			if (digits[j] != 0 && first == -1)
				first = j;
			cpy -= digits[j] * div;
			div /= 10;
		}

		for (j = 0; j < 18; j++) {
			if (digits[j] > digits[j+1]) 
				break;
		}
		
		if (j == 18) {
			printf("Case #%d: %ld\n", i+1, n);
			continue;
		}

		for (k = j+1; k < 19; k++) {
			digits[k] = 9;
		}

		while (j != first) {
			digits[j]--;
			if (digits[j] < digits[j-1]) {
				digits[j] = 9;
				j--;
				continue;
			}
			digits[first]++;
			break;
		}

		digits[first]--;

		n = 0;
		div = 1;
		for (j = 0; j < 19; j++) {
			n += digits[19-1-j]*div;
			div *= 10;
		}	

		printf("Case #%d: %ld\n", i+1, n);
	}

	return 0;
}
