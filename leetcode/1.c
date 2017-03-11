// 1. Two Sum
//
// Errors made during implementation...
// 		- line 47: forgot to add l to A
// 		- line 47: (typo?) had r - 1 + 1 rather than r - l + 1
// 		- Initially didn't return anything if no result was found,
// 		  causing compilation error.
//
// Notes...
// 		- Try to use the C standard library (quick sort and binary search).
// 		- Using a language with a hash map allows an O(n) solution

#include <stdlib.h>
#include <string.h>

int binary_search(int * A, int l, int r, int num) {
	if (l > r) return -1;
		
	int i = l + (r - l) / 2;
			
	if (A[i] == num) return i;
	else if(A[i] > num) {
		return binary_search(A, l, i - 1, num);
	} else {
		return binary_search(A, i + 1, r, num);
	}
}


void merge(int * A, int l, int m, int r) {
	int* B = (int*)malloc(sizeof(int)*(r - l + 1));
	int i = l, j = m + 1, k = 0;

	while (i <= m && j <= r) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}

	while (i <= m) {
		B[k] = A[i];
		i++; k++;
	}

	while (j <= r) {
		B[k] = A[j];
		j++; k++;
	}

	memcpy(A + l, B, sizeof(int)*(r - l + 1));
	free(B);
}


void merge_sort(int * A, int l, int r) {
	if (r <= l) return;    

	int mid = l + (r - l) / 2;

	// sort left and right halves
	merge_sort(A, l, mid);
	merge_sort(A, mid + 1, r);

	// combine
	merge(A, l, mid, r);
}


// Note: The returned array must be malloced, assume caller calls free().
int* twoSum(int* nums, int numsSize, int target) {
	int* result = (int*)malloc(sizeof(int)*2);

	/* 
	1. Copy and sort the array (n log n with merge sort)
	2. For each element in the array, search for the matching element to make the target (n log n with binary search)
	3. Find the index of the matching element (n)
	
	Together this should be O(n log n)
	*/

	int* B = (int*)malloc(sizeof(int)*numsSize);
	memcpy(B, nums, sizeof(int)*numsSize);
	merge_sort(B, 0, numsSize - 1);

	for (int i = 0; i < numsSize; i++) {
		int match = target - nums[i];
		if (binary_search(B, 0, numsSize - 1, match) >= 0) {

			// find the index of match in nums
			for (int j = 0; j < numsSize; j++) {
				if (nums[j] == match && i != j) {
					result[0] = i;
					result[1] = j;
					return result;
				}
			}
		}
	}

	/* Brute force
	Analysis:
	n-1 + n-2 + n-3 + ... + 1 = (n - 1) * n / 2
	= O(n^2)
	*//*
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}*/

	return result;
}
