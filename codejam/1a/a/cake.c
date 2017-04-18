#include <stdio.h>
#include <stdlib.h>

int empty(char* row, int length) {
	int result;

	for (int i = 0; i < length; i++) {
		if (row[i] != '?') {
			return 0;
		}
	}
	return 1;
}

int main(void) {

	int T;
	int r, c;
	scanf("%d ", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d ", &r, &c);
		char cake[r][c];
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%c", cake[i]+j);
			}
			scanf(" ");
		}

		for (int i = 0; i < r; i++) {
			if (empty(cake[i], c)) {
				continue;
			}
			char prev = '?';
			for (int j = 0; j < c; j++) {
				if (cake[i][j] == '?') {
					if (prev == '?') {
						continue;
					} else {
						cake[i][j] = prev;
					}
				} else {
					if (prev == '?') {
						for (int k = 0; k < j; k++) {
							cake[i][k] = cake[i][j];
						}
					}
					prev = cake[i][j];
				}
			}
		}

		if (empty(cake[0], c)) {
			int i = 1;
			while (cake[i][0] == '?') {
				i++;
			}

			for (int k = 0; k < i; k++) {
				for (int j = 0; j < c; j++) {
					cake[k][j] = cake[i][j];
				}
			}
		}

		for (int i = 1; i < r; i++) {
			if (cake[i][0] == '?') {
				for (int j = 0; j < c; j++) {
					cake[i][j] = cake[i-1][j];
				}
			}
		}

		printf("Case #%d:\n", t+1);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%c", cake[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
