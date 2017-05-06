#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int> > grid, char bomb, char empty) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 0)
				cout << empty;
			else
				cout << bomb;
		}
		cout << '\n';
	}
}


int main (void) {
	int N, R, C;
	int i, j, k;
	string s;
	cin >> R >> C >> N;

	// Read in initial state
	vector<vector<int> > grid(R);
	for (i = 0; i < R; i++) {
		cin >> s;
		for (j = 0; j < C; j++) {
			if (s[j] == '.') {
				grid[i].push_back(0);
			} else {
				grid[i].push_back(1);
			}
		}
	}

	if (N % 2 == 0) {
		display(grid, 'O', 'O');
	} else if (N == 1) {
		display(grid, 'O', '.');
	} else {
		vector<vector<int> > grid2(R);
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				if (grid[i][j] == 1 || (i > 0 && grid[i-1][j] == 1) ||
						(i < R-1 && grid[i+1][j] == 1) || (j > 0 && grid[i][j-1] == 1) ||
						(j < C-1 && grid[i][j+1] == 1)) {
					grid2[i].push_back(0);
				} else {
					grid2[i].push_back(1);
				}
			}
		}

		if ((N - 1) % 4 != 0) {
			display(grid2, 'O', '.');
		} else {
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (grid2[i][j] == 1 || (i >= 1 && grid2[i-1][j] == 1) || (i < R-1 && grid2[i+1][j] == 1) ||
							(j > 0 && grid2[i][j-1] == 1) || (j < C-1 && grid2[i][j+1] == 1)) {
						cout << '.';
					} else {
						cout << 'O';
					}
				}
				cout << '\n';
			}
		}
	}

	return 0;
}
