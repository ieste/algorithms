#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_green(int cycle_time, int now) {
	int red, orange;
	red = now / cycle_time % 2;
	if (!red) {
		orange = cycle_time - now % cycle_time <= 5;
		return !orange;
	}
	return 0;
}

int main() {

	int *times, a, b, c, count, now, j, min, seconds, minutes, hours;
	scanf("%d %d", &a, &b);
	while (a || b) {
		times = calloc(101, sizeof(int));
		times[0] = a;
		times[1] = b;
		count = 2;
		min = a < b ? a : b;
		do {
			scanf("%d", &c);
			times[count++] = c;
			min = c && c < min ? c : min;
		} while(c);
		count--;

		for (now = min; now <= 5 * 60 * 60; now++) {
			for (j = 0; j < count; j++) {
				if (!is_green(times[j], now)) {
					break;
				}
			}
			if (j == count) {
				break;
			}
		}

		if (now > 5 * 60 * 60) {
			printf("Signals fail to synchronise in 5 hours\n");
		} else {
			seconds = now % 60;
			minutes = (now / 60) % 60;
			hours = now / 60 / 60;
			printf("%02d:%02d:%02d\n", hours, minutes, seconds);
		}

		scanf("%d %d", &a, &b);
	}
	return 0;
}


