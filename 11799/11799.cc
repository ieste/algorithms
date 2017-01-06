#include <cstdio>

using namespace std;

int main(void) {

	int i, j, k;
	int T;
	int n;
	int max = 0;

	
	scanf("%d ", &T);

	for (i = 1; i <= T; i++) {

		scanf("%d ", &n);

		for (j = 0; j < n; j++) {
			scanf("%d ", &k);
			if (k > max) max = k;
		}

		printf("Case %d: %d\n", i, max);
		max = 0;
	}

	return 0;
}
