#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *SUITS = "SHDC";

int suittoi(char c) {
	int i;
	for (i = 0; i < 4; i++) {
		if (c == SUITS[i]) return i;
	}
	return -1;
}

char itosuit(int i) {
	if (i > 3 || i < 0) return -1;
	return SUITS[i];
}

int num(char c) {
	if (c >= '2' && c <= '9') {
		return c - '2';
	}
	switch(c) {
		case 'T':
			return 8;
		case 'J':
			return 9;
		case 'Q':
			return 10;
		case 'K':
			return 11;
		case 'A':
			return 12;
	}
	return -1;
}


int main() {
	char hand[42], *cards;
	int i, j, s, n, p1, p2, *counts, *stopped, best, all_stopped;
	while (fgets(hand, 42, stdin)) {
		p1 = 0;
		p2 = 0;
		counts = calloc(4, sizeof(int));
		cards = calloc(4 * 13, sizeof(char));
		stopped = calloc(4, sizeof(int));
		for (i = 0; i < 13; i++) {
			s = suittoi(hand[3*i+1]);
			n = num(hand[3*i]);
			cards[s*13+n] = 1;
			counts[s]++;
		}

		for (n = 0; n < 4; n++) {
			for (s = 0; s < 4; s++) {
				if (cards[s*13+12-n]) {
					p1 += 4 - n;
					p2 += 4 - n;
					if (counts[s] <= n) {
						p1--;
						p2--;
					}
					else if (n < 3) stopped[s] = 1;
				}
				if (!n) {
					if (counts[s] <= 1) p2 += 2;
					if (counts[s] == 2) p2++;
				}
			}
		}

		all_stopped = 1;
		for (i = 0; i < 4; i++) {
			if (!stopped[i]) all_stopped = 0;
		}

		if (p2 < 14) {
			printf("PASS\n");
		} else if (p1 >= 16 && all_stopped) {
			printf("BID NO-TRUMP\n");
		} else {
			best = 0;
			for (i = 1; i < 4; i++) {
				if (counts[i] > counts[best]) best = i;
			}
			printf("BID %c\n", itosuit(best));
		}
	}
	return 0;
}


