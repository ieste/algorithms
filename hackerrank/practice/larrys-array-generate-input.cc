#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

void l_rotate(int* arr, int index) {
	int tmp = arr[index];
	arr[index] = arr[index+1];
	arr[index+1] = arr[index+2];
	arr[index+2] = tmp;
}

void r_rotate(int* arr, int index) {
	int tmp = arr[index+2];
	arr[index+2] = arr[index+1];
	arr[index+1] = arr[index];
	arr[index] = tmp;
}

int main() {
	cout << "10\n";

	for (int i = 0; i < 10; i++) {
		cout << 1000 << "\n";

		int array[1000];
		int* arr = (int*)array;

		for (int j = 0; j < 1000; j++) {
			arr[j] = j+1;
		}	

		int r;
		for (int j = 0; j < 1000; j++) {
			r = rand() % 997;
			r_rotate(arr, r);
			r = rand() % 997;
			l_rotate(arr, r);
		}

		for (int j = 0; j < 1000; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
}
