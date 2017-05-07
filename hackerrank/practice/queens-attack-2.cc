#include <iostream>
#include <vector>

using namespace std;

int main (void) {
	
	int n, k, rq, cq;
	vector<int> dist(8);

	cin >> n >> k >> rq >> cq;

	dist[0] = cq - 1; // 9 o'clock
	dist[1] = n - rq; // 12 o'clock
	dist[2] = n - cq; // 3 o'clock
	dist[3] = rq - 1; // 6 o'clock
	dist[4] = dist[0] < dist[1] ? dist[0] : dist[1];
	dist[5] = dist[1] < dist[2] ? dist[1] : dist[2];
	dist[6] = dist[2] < dist[3] ? dist[2] : dist[3];
	dist[7] = dist[3] < dist[0] ? dist[3] : dist[0];

	int r, c, ro, co;
	for (int i = 0; i < k; i++) {
		cin >> ro >> co;
		r = rq - ro;
		c = co - cq;
		if (r == 0) {
			if (c > 0) {
				if (c <= dist[2])
					dist[2] = c-1;
			} else {
				if (c * -1 <= dist[0])
					dist[0] = c * -1 - 1;
			}
		} else if (c == 0) {
			if (r > 0) {
				if (r <= dist[3]) {
					dist[3] = r-1;
				}
			} else {
				if (r * -1 <= dist[1]) {
					dist[1] = r * -1 - 1;
				}
			}
		} else if (r == c) {
			if (r > 0) {
				if (r <= dist[6])
					dist[6] = r-1;
			} else {
				if (r * -1 <= dist[4])
					dist[4] = r *-1 - 1;
			}
		} else if (r == c * -1) {
			if (r > 0) {
				if (r <= dist[7])
					dist[7] = r - 1;
			} else {
				if (c <= dist[5])
					dist[5] = c - 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 8; i++) {
		//cout << i << " " << dist[i] << '\n';
		result += dist[i];
	}

	cout << result << '\n';

	return 0;
}
