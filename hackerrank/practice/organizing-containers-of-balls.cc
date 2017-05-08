#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int Q, q, n, i, j, k, c, t, sum;
	cin >> Q;
	for (q = 0; q < Q; q++) {
		cin >> n;
		vector<vector<int> > M (n, vector<int>(n));
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> M[i][j];
			}
		}

		// do the thing
		vector<int> capacity(n);
		vector<int> counts(n);

		for (c = 0; c < n; c++) {
			sum = 0;
			for (t = 0; t < n; t++) {
				sum += M[c][t];
			}
			capacity[c] = sum;
		}

		for (t = 0; t < n; t++) {
			sum = 0;
			for (c = 0; c < n; c++) {
				sum += M[c][t];
			}
			counts[t] = sum;
		}

		sort(capacity.begin(), capacity.end());
		sort(counts.begin(), counts.end());

		for (i = 0; i < n; i++) {
			//cout << capacity[i] << ' ' << counts[i] << '\n';
			if (capacity[i] != counts[i])
				break;
		}

		if (i < n)
			cout << "Impossible\n";
		else
			cout << "Possible\n";

	}

	return 0;
}
