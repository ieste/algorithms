#include <cstdio>

using namespace std;

int main(void) {

	int T;
	int m, n;
	int t, tp, tmp, temp;


	scanf("%d ", &T);

	for (int i = 0; i < T; i++) {
		
		scanf("%d %d ", &n, &m);

		n -= 2; m -= 2;
		t = n / 3;
		tp = m / 3;
		if (n % 3) t += 1;
		if (m % 3) tp += 1;

		printf("%d\n", t * tp);
	}

	return 0;
}
