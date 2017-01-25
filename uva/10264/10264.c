#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, j, k, T;
	int N, max;
	int t, tp, tmp;
	int A[33000];
	int B[33000];

	while(scanf("%d ", &N) == 1) {

		for (i = 0; i < (1 << N); i++) {
			scanf("%d ", A+i);
		}

		max = 0;

		for (i = 0; i < (1 << N); i++) {
			B[i] = 0;
			t = 1;
			for (j = 0; j < N; j++) {
				B[i] += A[i ^ t];
				t <<= 1;
			}
		}


		for (i = 0; i < (1 << N); i++) {
			for (t = 1, j = 0; j < N; t <<= 1, j++) {
				if (!(i & t)) {
					if (B[i ^ t] + B[i] > max)
						max = B[i ^ t] + B[i];
				}
			}
		}

		printf("%d\n", max);
	}
    
	

    return 0;
}
