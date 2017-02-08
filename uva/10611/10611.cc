#include <cstdio>

int x, A[50000];


int find_predecessor(int l, int r) {

	int m;

	if (r < l) return l - 1;
	
	if (l == r) {
		if (A[l] > x) return l - 1;
		return l;
	}

	m = l + (r - l) / 2;
	if (A[m] == x) return m;
	if (A[m] > x) return find_predecessor(l, m-1);
	return find_predecessor(m+1, r);	
}


int find_pre(int l, int r) {
	if (l > r) return r;
	int m = (l + r) / 2;
	if (A[m] <= x) return find_pre(m+1, r);
	return find_pre(l, m-1);
}


int main(void) {

	int N, Q;
	int tp, tmp;
	int s, t;

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", A+i);
	}

	scanf("%d ", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d ", &x);

		tp = find_pre(0, N-1);
		tmp = tp;

		while (tp >= 0 && A[tp] == x) tp--;
		if (tp < 0) printf("X ");
		else printf("%d ", A[tp]);

		while (++tmp < N) {
			if(A[tmp] > x) break;
		}
		if (tmp < N) printf("%d\n", A[tmp]);
		else printf("X\n");
	}

	return 0;
}

