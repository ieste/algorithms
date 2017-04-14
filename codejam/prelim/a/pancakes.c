#include <stdio.h>
#include <stdlib.h>

void flip (char* arr, int idx, int k) {
	for (int i = idx; i < idx + k; i++) {
		if (arr[i] == '-')
			arr[i] = '+';
		else
			arr[i] = '-';
	}
}

int main (void) {
	int T;
	int i, j, k, n, count;
	char pancakes[1001];

	scanf("%d ", &T);

	for (i = 0; i < T; i++) {
		n = 1;
		scanf("%c", pancakes);
		while(pancakes[n-1] != ' ') {
			scanf("%c", pancakes+n);
			n++;
		}
		n--;

		scanf("%d ", &k);

		count = 0;
		for(j = 0; j <= n-k; j++) {
			if (pancakes[j] == '-') {
				flip(pancakes, j, k);
				count++;
			}
		}

		for (j = n-k+1; j < n; j++) {
			if (pancakes[j] == '-')
				break;
		}

		printf("Case #%d: ", i+1);
		if (j < n)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", count);
	}

	return 0;
}

