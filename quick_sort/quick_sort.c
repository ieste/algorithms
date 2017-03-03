// Quick Sort
//
// Algorithm:
// 		Base case - if n = 1, return
// 		Inductive Case
// 			- randomly pick an integer p in A called the pivot
// 			- Rearrange the integers in an array A' such that all integers
// 			  smaller than p are before p and all integers larger than p are
// 			  after p.
// 			- sort the part of A' before p recursively
// 			- sort the part of A' after p recursively
//
// 	Analysis:
// 		In the worst case, quick sort's running time will be O(n^2), no better than selection sort.
// 		However, in expectation, the running time is O(n log n). That is, on average it will have
// 		a running time of O(n log n)
//
// 	Mistakes I made while implementing the algorithm:
// 		accidentally freed B to early
//		when sorting the upper half, calculated length as n - r + 1 rather than n - r - 1
//
//	Notes on my implementation:
//		It is possible to do this without making a copy of A, however such a solution might
//		be slightly less readable.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int test_data[] = {0, 2, 73, 1, 45, 23, 12, 64, 1, 3, 5, 6, 46, 23, 54};
int size = 15;

void quick_sort(int* A, int n) {
	
	if (n <= 1) {
		//printf("Nothing to sort.");
		return;
	}

	int p = rand() % n;
	int* B = (int*)malloc(n * sizeof(int));
	int l = 0, r = n - 1;

	memcpy(B, A, n * sizeof(int));

	for (int j = 0; j < n; j++) {
		if (B[j] < B[p]) {
			A[l] = B[j];
			l++;
		} else if (B[j] > B[p]) {
			A[r] = B[j];
			r--;
		}
	}

	quick_sort(A, l);
	quick_sort(A + r + 1, n - r - 1);

	while (l <= r) {
		A[l] = B[p];
		l++;
	}

	free(B);
}



int main(void) {

	printf("Input: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test_data[i]);
	}

	quick_sort(test_data, size);

	printf("\nOutput: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test_data[i]);
	}
	printf("\n");

	return 0;
}




