#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, p, i, j, rq_met, max_rq_met, rfp=0;
	char leader[81], rq[81], proposal[81];
	float cost, min_cost;
	scanf("%d %d\n", &n, &p);
	while (n || p) {
		rfp++;
		max_rq_met = 0;
		min_cost = 0;
		for (i = 0; i < n; i++) {
			scanf("%80[^\n]\n", rq);
		}
		for (i = 0; i < p; i++) {
			scanf("%80[^\n]\n", proposal);
			scanf("%f %d\n", &cost, &rq_met);
			for (j = 0; j < rq_met; j++) {
				scanf("%80[^\n]\n", rq);
			}
			if (rq_met > max_rq_met) {
				max_rq_met = rq_met;
				min_cost = cost;
				strcpy(leader, proposal);
			} else if (rq_met == max_rq_met && cost < min_cost) {
				min_cost = cost;
				strcpy(leader, proposal);
			}
		}
		printf("RFP #%d\n%s\n", rfp, leader);
		scanf("%d %d\n", &n, &p);
		if (n || p) putchar('\n');
	}
	return 0;
}
