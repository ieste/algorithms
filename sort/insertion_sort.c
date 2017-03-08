#include <stdio.h>
#include <stdlib.h>

int test[] = {1, 4, 2, 64, 12, 62, 86, 1, 23, 863, 1234, 42, 1, 5};
int size = 14;

void insertion_sort(int * A, int n) {
	int j, tmp;

	for (int i = 0; i < n; i++) {
		j = i;
		while (j > 0 && A[j] < A[j-1]) {
			tmp = A[j];
			A[j] = A[j-1];
			A[j-1] = tmp;
			j--;
		}
	}
}



int main(void) {

	printf("Input: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}

	insertion_sort(test, size);

	printf("\nOutput: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");

	return 0;
}
