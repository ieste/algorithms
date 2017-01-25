#include <cstdio>

using namespace std;

int main(void) {

	int N, B, H, W;
	int i, j, k;
	int t, tp, tmp, temp;

	int min, max;

	//scanf("%d %d %d %d ", &N, &B, &H, &W);

	while(scanf("%d %d %d %d ", &N, &B, &H, &W) != EOF) {

		max = B/N;
		min = max + 1;

		for (i = 0; i < H; i++) {
			scanf("%d ", &t);

			// if this can't be the best price, read up to next price
			if (t > max || (t < max && t > min)) {
				for (j = 0; j < W; j++) {
					scanf("%d ", &tp);
				}
			}
			
			// if this could be the best price check there is a valid week
			else {
				for (j = 0; j < W; j++) {
					scanf("%d ", &tmp);
					if (tmp >= N) min = t;
				}
			}
		}

		if (max < min) printf("stay home\n");
		else printf("%d\n", N * min);

		//scanf("%d %d %d %d ", &N, &B, &H, &W);

	}

	return 0;
}
