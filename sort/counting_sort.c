#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT	10000

int test[] = {10000, 1, 53, 3544, 234, 664, 64, 5, 675, 329, 1, 1};
int size = 12;

void counting_sort(int * A, int n) {

	int * B = (int*)malloc(sizeof(int) * (MAX_INT + 1));
	memset((void*)B, 0, sizeof(int) * (MAX_INT + 1));
	
	for (int i = 0; i < n; i++) {
		// Increment count in B of A[i]
		B[A[i]]++;
	}

	int k = 0;
	for (int i = 0; i < MAX_INT + 1; i++) {
		for (int j = 0; j < B[i]; j++) {
			A[k++] = i;
		}
	}
}


int main(void) {

	printf("Input: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}

	counting_sort(test, size);

	printf("\nOutput: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");

	return 0;
}
