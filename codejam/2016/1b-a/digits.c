#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int T, t, i, j, k, a, b;
	scanf("%d ", &T);

	for (t = 0; t < T; t++) {
		char c;
		int chars[256];
		for (i = 0; i < 256; i++) {
			chars[i] = 0;
		}
		scanf("%c", &c);
		while (c != '\n') {
			chars[c]++;
			scanf("%c", &c);
		}

		int nums[10];
		for (i = 0; i < 10; i++) {
			nums[i] = 0;
		}

		nums[8] = chars['G'];
		nums[6] = chars['X'];
		nums[2] = chars['W'];
		nums[4] = chars['U'];
		nums[0] = chars['Z'];
		chars['S'] -= nums[6];
		nums[7] = chars['S'];
		chars['V'] -= nums[7];
		nums[5] = chars['V'];
		chars['I'] -= nums[8] + nums[6] + nums[5];
		nums[9] = chars['I'];
		chars['O'] -= nums[0] + nums[2] + nums[4];
		nums[1] = chars['O'];
		chars['H'] -= nums[8];
		nums[3] = chars['H'];

		printf("Case #%d: ", t+1);
		for (i = 0; i < 10; i++) {
			for (j = 0; j < nums[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}

	return 0;
}
