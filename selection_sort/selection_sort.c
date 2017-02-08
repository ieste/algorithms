#include <stdio.h>

int A[50];
int N = 5;

void selection_sort(int n) {
	int tmp, max = 0;
	
	if (n == 1) return;

	for (int i = 1; i < n; i++) {
		if (A[i] > A[max]) max = i;
	}

	tmp = A[n-1];
	A[n-1] = A[max];
	A[max] = tmp;

	selection_sort(n-1);
}

int main(void) {

	A[0] = 2332; A[1] = 3; A[2] = 124; A[3] = 1000; A[4] = 0;
	selection_sort(N);
	
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

	return 0;
}
