#include <iostream>
#include <vector>

using namespace std;

int main (void) {

	int M, N, R, i, j, k;

	cin >> N >> M >> R;

	vector<vector<int> > matrix(N, vector<int>(M));

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	int layers = (M < N ? M : N) / 2;
	int size, width, height;
	int r;

	for (i = 0; i < layers; i++) {
		// rotate each "layer" of the matrix
		width = M - 2 * i;
		height = N - 2 * i;
		size = 2 * width + 2 * height - 4;
		r = R % size;

		if (r == 0)
			continue;

		vector<int> rotated(size);
		for (j = 0; j < width; j++)
			rotated[j] = matrix[i][i+j];
		
		for (j = 0; j < height - 2; j++)
			rotated[width+j] = matrix[1+i+j][M-1-i];

		for (j = 0; j < width; j++) 
			rotated[width+height-2+j] = matrix[N-1-i][M-1-i-j];

		for (j = 0; j < height - 2; j++)
			rotated[2*width+height-2+j] = matrix[N-1-i-j-1][i];
		
		/*
		for (j = 0; j < size; j++) 
			cout << rotated[j] << " ";
		cout << '\n';
		*/

		// perform rotation
		for (j = 0; j < width; j++)
			matrix[i][i+j] = rotated[(j+r) % size];
		for (j = 0; j < height - 2; j++) 
			matrix[1+i+j][M-1-i] = rotated[(width+j+r) % size];
		for (j = 0; j < width; j++)
			matrix[N-1-i][M-1-i-j] = rotated[(width+height-2+j+r) % size];
		for (j = 0; j < height - 2; j++)
			matrix[N-1-i-j-1][i] = rotated[(2*width+height-2+j+r) % size];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
