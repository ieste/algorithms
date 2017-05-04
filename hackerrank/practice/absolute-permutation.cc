/*
	1  2  3  4  5  6  7  8  9  10
	2  1  4  3  6  5
	3  4  1  2  7  8  5  6
	4  5  6  1  2  3

0: always the same array
1: needs an even number of elements
2: needs a multiple of 4 elements
3: needs multiple of 6 elements

*/

#include <iostream>

using namespace std;

int main() {
	int T, t, i, j, k, n, tmp, temp, tp;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> n >> k;
		if (k == 0) {
			for (i = 1; i < n; i++) {
				cout << i << " ";
			}
			cout << n << "\n";
		}
		else if (n % (k * 2) != 0) {
			cout << "-1\n";
		} else {
			for (i = 0, tp = n / (k * 2); i < tp; i++) {
				for (j = 1; j <= k; j++) {
					cout << i * k * 2 + j + k << " ";
				}
				for (j = 1; j <= k; j++) {
					cout << i * k * 2 + j << " ";;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
