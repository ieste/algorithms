#include <stdio.h>
#include <stdlib.h>

int 
int main(void) {
	
	int T;
	int t, i, j, k;
	int n;
	scanf("%d ", &T);

	for (t = 0; t < T; t++) {
		scanf("%d ", &n);
		//int lines[2*n-1][n];
		int** lines = malloc((2*n-1)*sizeof(int*));
		for (i = 0; i < 2*n-1; i++) {
			lines[i] = malloc(n*sizeof(int));
		}

		for (i = 0; i < 2*n-1; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d ", &lines[i][j]);
			}
		}



	}

	return 0;
} 
