/*
	My intuition on seeing this question was that a greedy solution must exist whereby
	we work through the array, first moving element 1 to its correct position, then 2,
	etc, and then check if items n-2 and n-1 are correct. Testing with randomly 
	generated data confirmed this solution. This solution has a time complexity of
	O(N^2) for each test case. Give a problem size of 10 test cases (t) and 100 
	elements (n) in each array, this solution is satisfactory.
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


void l_rotate(int* arr, int index) {
	int tmp = arr[index];
	arr[index] = arr[index+1];
	arr[index+1] = arr[index+2];
	arr[index+2] = tmp;
}

int main() {
	int T, n;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		int array[n];
		int *arr = (int*)array;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// greedily try to solve it
		int next = 1;
		int i;
		while (n > 3) {
			i = 0;
			while (arr[i] != next)
				i++;

			if (i == n - 1) {
				l_rotate(arr, i-2);
				i--;
			}

			while (i != 0) {
				l_rotate(arr, i-1);
				i--;
			}

			arr = arr + 1;
			n -= 1;
			next++;
		}

		while (arr[0] != next) {
			l_rotate(arr, 0);
		}

		if (arr[1] == next + 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}




