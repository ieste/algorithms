#include <stdio.h>


int binary_search(int x, int * array, int start, int end);


int main(void) {
	
	int array[10000];
	int N, M, i, j;

	array[0] = 1;
	printf("{1}, 1: %d\n", binary_search(1, array, 0, 1));
	printf("{1}, 0: %d\n", binary_search(0, array, 0, 1));
	printf("{1}, 5: %d\n", binary_search(5, array, 0, 1));

	array[1] = 5;
	printf("{1, 5}, 1: %d\n", binary_search(1, array, 0, 2));
	printf("{1, 5}, 5: %d\n", binary_search(5, array, 0, 2));
	printf("{1, 5}, 0: %d\n", binary_search(0, array, 0, 2));
	printf("{1, 5}, 4: %d\n", binary_search(4, array, 0, 2));
	printf("{1, 5}, 7: %d\n", binary_search(7, array, 0, 2));

	array[2] = 7;
	printf("{1, 5, 7}, 1: %d\n", binary_search(1, array, 0, 3));
	printf("{1, 5, 7}, 5: %d\n", binary_search(5, array, 0, 3));
	printf("{1, 5, 7}, 7: %d\n", binary_search(7, array, 0, 3));
	printf("{1, 5, 7}, 0: %d\n", binary_search(0, array, 0, 3));
	printf("{1, 5, 7}, 6: %d\n", binary_search(6, array, 0, 3));
	printf("{1, 5, 7}, 10: %d\n", binary_search(10, array, 0, 3));

	return 0;
}


int binary_search(int x, int * array, int start, int end) {

	int middle;
	//printf("%d %d %d\n", x, start, end);

	if (start == end) return 0;
	if (end - start == 1) return array[start] == x;

	middle = start + (end - start) / 2;	
	if (array[middle] == x) return 1;
	if (array[middle] < x) return binary_search(x, array, middle+1, end);
	return binary_search(x, array, start, middle);
}
