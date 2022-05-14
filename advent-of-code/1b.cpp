#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	int first, previous, c, sum;
	c = first = getchar();

	while(1) {
		previous = c;	
		c = getchar();
		if (c < '0' || c > '9') 
			break;
		if (c == previous) {
			sum += c - '0';
		}
	}

	if (previous == first) {
		sum += first - '0';
	}

	cout << sum;

	return 0;
}
