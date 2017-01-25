#include <cstdio>

using namespace std;

int main(void) {

	int H, U, D, F;

	int height = 0, slip, day, climbs;
	int mult = 10000;

	scanf("%d %d %d %d ", &H, &U, &D, &F);

	while(H) {

		D = D * mult;
		H = H * mult;
		U = U * mult;
		slip = U * F / 100;
		height = U;
		climbs = U;
		day = 1;

		//printf("day: %d height: %d climbs: %d falls: %d\n", day, height-D, climbs, D);

		while (height <= H && height-D >= 0) {
			height -= D;
			day++;
			climbs = climbs - slip;
			if (climbs < 0) climbs = 0;
			height += climbs;

			//printf("day: %d height: %d climbs: %d falls: %d\n", day, height-D, climbs, D);
		}

		// Print outcome
		if (H < height) {
			printf("success on day %d\n", day);
		} else {
			printf("failure on day %d\n", day);
		}

		scanf("%d %d %d %d ", &H, &U, &D, &F);
	}

	return 0;
}
