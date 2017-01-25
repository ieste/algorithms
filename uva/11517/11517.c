#include <cstdio>
#include <cstring>
#define INF 1000000000
int S, A[105], B[10005][105], n;

int coin(int S, int i) {
	int t, tp, tmp;

	if (S <= 0) 
		return -S;

	if (i == n) 
		return INF;

	if (B[S][i] != -1)
		return B[S][i];

	t = coin(S-A[i], i+1);
	tp = coin(S, i+1);
	return B[S][i] =  (t < tp ? t : tp);
}


int change(int V, int i) {
	int t, tp, tmp;

	if (V == 0)
		return 0;

	if (V < 0)
		return INF;

	if (i == n)
		return INF;

	if (B[V][i] != -1)
		return B[V][i];

	t = 1 + change(V - A[i], i + 1);
	tp = change(V, i +1);
	return B[V][i] = (t < tp ? t : tp);

}


int main(void)
{
	int i, j, k, T;
	int t, tp, tmp;

	scanf("%d ", &T);

	while(T--) {
		scanf("%d ", &S); 
		scanf("%d ", &n); 

		for (i = 0; i < n; i++) {
			scanf("%d ", A + i);
		}
	
		// Do the thing
		memset(B, -1, sizeof(B));
		t = coin(S, 0);
		memset(B, -1, sizeof(B));
		tp = change(S + t, 0);

		printf("%d %d\n", S + t, tp);
	}

	return 0;

}



