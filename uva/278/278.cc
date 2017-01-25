

#include <cstdio>

#define MIN(X, Y)	((X) < (Y) ? (X) : (Y))
#define CEIL(X)		((X) % 2 ? (X)/2 + 1 : (X)/2)

int main(void) {

	int i, j, k;
	int tp, tmp;
	char t;
	int T;

	scanf("%d ", &T);

	while(T--) {

		scanf("%c %d %d ", &t, &tp, &tmp);

		switch (t) {

			case 'r':
				j = MIN(tp, tmp);
				break;

			case 'k':
				j = CEIL(tp*tmp);
				break;
			case 'Q':
				j = MIN(tp, tmp);
				break;

			case 'K':
				j = CEIL(tp) * CEIL(tmp);

		}


		printf("%d\n", j);
	}

	return 0;
}
