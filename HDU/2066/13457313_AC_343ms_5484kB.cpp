#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 1005;

int n;
int maps[maxn][maxn];
int be[maxn];
int en[maxn];
int dis[maxn];
int vis[maxn];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(be, 0, sizeof(be));
	memset(en, 0, sizeof(en));
}

void dijkstra(int pos) {
	for(int i=1; i<=n; i++) {
		dis[i] = maps[pos][i];
	}
	dis[pos] = 0;
	vis[pos] = true;
	for(int r=2; r<=n; r++) {
		int p = 0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p] > dis[i]) {
				p = i;
			}
		}
		vis[p] = true;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i] > dis[p] + maps[p][i]) {
				dis[i] = dis[p] + maps[p][i];
			}
		}
	}
}

int main() {
	int m, p, q;
	while(~scanf("%d%d%d", &m, &p, &q)) {
		init();
		n = 0;
		for(int i=0; i<m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(maps[u][v] > w) {
				maps[u][v] = maps[v][u] = w;
			}
			n = max(n, max(u, v));
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d\t", maps[i][j]);
			}
			puts("");
		}
		*/
		for(int i=0; i<p; i++) {
			scanf("%d", &be[i]);
		}
		for(int i=0; i<q; i++) {
			scanf("%d", &en[i]);
		}
		int ans = inf;
		for(int i=0; i<p; i++) {
			memset(dis, inf, sizeof(dis));
			memset(vis, false, sizeof(vis));
			dijkstra(be[i]);
			for(int j=0; j<q; j++) {
				ans = min(ans, dis[en[j]]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}