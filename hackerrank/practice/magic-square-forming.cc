#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main (void) {

	int result;

	// Generate magic squares
	vector<vector<int> > magic_squares(0);
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sum;
	int i, j, k;
	do {
		sum = arr[0]+arr[1]+arr[2];
		if (sum == arr[3]+arr[4]+arr[5] && sum == arr[6]+arr[7]+arr[8] &&
				sum == arr[0]+arr[3]+arr[6] && sum == arr[1]+arr[4]+arr[7] &&
				sum == arr[2]+arr[5]+arr[8] && sum == arr[0]+arr[4]+arr[8] &&
				sum == arr[2]+arr[4]+arr[6]) {
			vector<int> square(9);
			for (i = 0; i < 9; i++) {
				square[i] = arr[i];
			}
			magic_squares.push_back(square);
		}
	} while (next_permutation(arr, arr+9));

	// Read in input
	vector<int> in(9);
	for (i = 0; i < 9; i++)
		cin >> in[i];

	// Find minimum difference
	int min = 1000000000;
	for(i = 0; i < magic_squares.size(); i++) {
		sum = 0;
		for (j = 0; j < 9; j++)
			sum += abs(in[j] - magic_squares[i][j]);
		min = min < sum ? min : sum;
	}
	cout << min << '\n';

	return 0;
}
