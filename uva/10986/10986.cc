#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

#define INF 1000000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


vector<vector<pair<int, int> > > G;
int n, m, S, T;

int main(void)
{
	int i, j, k, Test;
	int t, tp, tmp, temp;

	scanf("%d ", &Test);

	for (t = 1; t <= Test; t++) {
		scanf("%d %d %d %d ", &n, &m, &S, &T);

		G.clear();

		for (i = 0; i < n; i++)
			G.push_back(vector<pair<int, int> >());
		
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &tp, &tmp, &temp);
			G[tp].push_back(pair<int, int>(temp, tmp));
			G[tmp].push_back(pair<int, int>(temp, tp));
		}

		// Do the thing
		priority_queue<ii, vii, greater<ii> > pq;
		pq.push(ii(0, S));
		vi dist(n, INF); 
		dist[S] = 0;

		while(!pq.empty()) {
			ii p = pq.top();
			pq.pop();
			if (p.first > dist[p.second])
				continue;
			for (i = 0; i < G[p.second].size(); i++) {
				tp = G[p.second][i].first + p.first;
				if (tp < dist[G[p.second][i].second]) {
					dist[G[p.second][i].second] = tp;
					pq.push(ii(tp, G[p.second][i].second));
				}				
			}
		}
		printf("Case #%d: ", t);
		if (dist[T] == INF) {
			printf("unreachable\n");
		} else {
			printf("%d\n", dist[T]);
		}
	}
	return 0;
}
