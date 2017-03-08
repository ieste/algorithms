// Selection Sort
//
// Algorithm:
// 		Scan through the whole list to find the smallest element.
// 		Swap smallest element with item 0
// 		Repeat on sublist 1 to n-1


#include <stdio.h>

int test[] = {2332, 3, 124, 1000, 0};
int size = 5;

void selection_sort(int* A, int n) {
	int tmp, min_idx = 0;
	
	if (n <= 1) return;

	for (int i = 1; i < n; i++) {
		if (A[i] < A[min_idx]) min_idx = i;
	}

	tmp = A[0];
	A[0] = A[min_idx];
	A[min_idx] = tmp;

	selection_sort(A + 1, n-1);
}


int main(void) {

	printf("Input: ");
	for(int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}

	selection_sort(test, size);

	printf("\nOutput: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");

	return 0;
}
