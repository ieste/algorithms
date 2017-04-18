#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare (const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int minKits(int amt, int needed) {
	double min =  ceil((double)amt / ((double)needed * 1.1));
	double max = floor((double)amt / ((double)needed * 0.9));

	if (min > max)
		return 0;

	return (int)min;
}

int maxKits(int amt, int needed) {
	double min =  ceil((double)amt / ((double)needed * 1.1));
	double max = floor((double)amt / ((double)needed * 0.9));

	if (min > max)
		return 0;

	return (int)max;
}



int main(void) {
	int T;
	int n, p, result;

	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		result = 0;
		scanf("%d %d ", &n, &p);

		int req[n];
		for (int i = 0; i < n; i++) {
			scanf("%d ", req+i);
		}

		int ing[n][p];
		int min[n][p];
		int max[n][p];
		int amt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				scanf("%d ", &ing[i][j]);
			}
			qsort(ing[i], p, sizeof(int), compare);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				min[i][j] = minKits(ing[i][j], req[i]);
				max[i][j] = maxKits(ing[i][j], req[i]);
				printf("%d-%d  ", min[i][j], max[i][j]);
			}
			printf("\n");
		}

		int ptrs[n];
		for (int i = 0; i < n; i++) {
			ptrs[i] = 0;
		}

		result = 0;
		int i;
		int k;
		for (; ptrs[0] < p; ptrs[0]++) {
			k = min[0][ptrs[0]];
			for (i = 1; i < n; i++) {
				while (ptrs[i] < p && max[i][ptrs[i]] < k) {
					ptrs[i]++;
				}
				if (ptrs[i] == p) {
					break;
				}

				if (min[i][ptrs[i]] > k) {
					k = min[i][ptrs[i]];
				}
			}

			if (i < n) {
				break;
			}

			for (i = 0; i < n; i++) {
				//printf("k is %d, min %d max %d\n", k, min[i][ptrs[i]], max[i][ptrs[i]]);
				if (k < min[i][ptrs[i]] || k > max[i][ptrs[i]])
					break;
			}

			if (i == n && k > 0) {
				result += 1;
				//printf("\n %d", ptrs[0]);
				for (i = 1; i < n; i++) {
					//printf("%d ", ptrs[i]);
					ptrs[i]++;
				}
			}
		}
			
		printf("Case #%d: %d\n", t+1, result);
	}

	return 0;
}
