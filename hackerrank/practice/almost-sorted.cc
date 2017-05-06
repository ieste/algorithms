#include <iostream>
#include <vector>

using namespace std;

int main (void) {
	int n;
	cin >> n;
	vector<int> arr(n);

	int decr = 0;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i > 0 && arr[i] < arr[i-1]) {
			if (decr == 0) 
				l = i - 1;
			decr++;
			r = i;
		}
	}

	if (decr == 0) {
		cout << "yes";
	} else {
		if (decr == 1) {
			int val = arr[l];
			for (r = l+1; r < n; r++) {
				if ((r == n - 1 || arr[l] < arr[r+1]) && arr[l] >= arr[r-1]  
						&& (arr[r] <= arr[l+1] && (l == 0 || arr[r] > arr[l-1])))
					break;
			}
			if (r < n) {
				cout << "yes\nswap " << l+1 << " " << r+1;
			} else {
				cout << "no";
			}
		} else if (decr == 2) {
			if ((r == n - 1 || arr[l] < arr[r+1]) && arr[l] >= arr[r-1] && (l == 0 || arr[r] > arr[l-1])
					&& arr[r] <= arr[l+1])
				cout << "yes\nswap " << l+1 << " " << r+1;
			else
				cout << "no";
		} else {
			int i;
			for (i = l+2; i <= r; i++) {
				if (arr[i-1] < arr[i])
					break;
			}
			if (i <= r) {
				cout << "no";
			} else {
				if ((l == 0 || arr[r] > arr[l-1]) && (r == n-1 || arr[l] < arr[r+1]))
					cout << "yes\nreverse " << l+1 << " " << r + 1;
				else cout << "no";
			}
		}
	}
	return 0;
}
