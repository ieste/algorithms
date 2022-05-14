#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int cases;
	long a, b;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%ld %ld", &a, &b);

		if (a > b) {
			puts(">");
		} else if (a < b) {
			puts("<");
		} else if (a == b) {
			puts("=");
		}
	}
	return 0;
}
