#include <stdlib.h>
#include <stdio.h>

int test[] = {5, 234, 12, 0, 22, 1, 6, 4, 7, 2, 6, 23, 67, 125};
int size = 14;

void bubble_sort(int * A, int n) {
	int tmp;
	int swap = 1;

	if (n <= 1) return;

	while (swap > 0) {
		swap = 0;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] > A[i+1]) {
				tmp = A[i]; 
				A[i] = A[i+1]; 
				A[i+1] = tmp;
				swap = 1;
			}
		}
	}
}



int main(void) {

	printf("Input: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}

	bubble_sort(test, size);

	printf("\nOutput: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");

	return 0;
}
