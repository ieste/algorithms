
/* Merge Sort
 *
 * COMPLEXITY: O(n log n)
 *
 * IMPLEMENTATION:
 * Base Case: when the problem size is 1 or 0 the array is already sorted.
 * Inductive Case: has three steps - recursively sort each half of the array and then
 * 				   merge the two together.
 * Merging: set i and j to 1. If A1[i] is smaller than A2[j], append A1[i] to A and increase i by 1.
 * 			otherwise, append A2[j] to A and increase j by 1. Repeat until i > len(A1) or j > len(A2).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[] = {4, 3, 2, 243, 4, 6, 395, 8};
//int A[] = {1};
int n = 8;
int B[1000];

void merge(int * a1, int * a2, int * a, int n1, int n2) {
	int i = 0, j = 0;
	int k = 0;

	while (i < n1 && j < n2) {
		if (a1[i] < a2[j]) {
			a[k] = a1[i];
			i++; k++;
		} else {
			a[k] = a2[j];
			j++; k++;
		}
	}
	
	while (j < n2) {
		a[k] = a2[j];
		j++; k++;
	}

	while (i < n1) {
		a[k] = a1[i];
		i++; k++;
	}
}

void merge_sort(int * a, int n) {
	
	if (n < 2) return;

	int m = n/2;
	merge_sort(a, m);
	merge_sort(a+m, n-m);

	// copy a1 and a2
	memcpy(B, a, sizeof(int) * m);
	memcpy(B+m, a+m, sizeof(int) * (n-m));
	merge(B, B+m, a, m, n-m);
}

int main(void) {

	merge_sort(A, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}
