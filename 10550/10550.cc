#include <cstdio>

using namespace std;

int main(void) {

	int a, b, c, d;
	int deg;

	scanf("%d %d %d %d ", &a, &b, &c, &d);

	while ((a + b + c + d) != 0) {

		deg = 1080;

		if (a >= b) deg += ((a - b) * 9);
		else if (a == 0) deg += ((40 - b) * 9);
		else deg += (((40 - b) + a) * 9);
		
		if (b <= c) deg += (c - b) * 9;
		else deg += ((c + (40 - b)) * 9);

		if (c >= d) deg += (c - d) * 9;
		else if (c == 0) deg += (40 - d) * 9;
		else deg += ((40 - d) + c) * 9;

		printf("%d\n", deg);

		scanf("%d %d %d %d ", &a, &b, &c, &d);


	}

	return 0;
}
