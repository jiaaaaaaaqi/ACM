#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int m,n;
int maps[105][105];
int pri[105];
int dis[105];
int lev[105];
bool vis[105];

void init() {
	memset(pri, 0, sizeof(pri));
	memset(lev, 0, sizeof(lev));
	memset(maps, inf, sizeof(maps));
}

int dijkstra() {
	for(int i=1; i<=n; i++)
		dis[i] = maps[0][i];
	dis[0]=0;
	for(int r=2; r<=n; r++) {
		int p;
		int va=inf;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && va > dis[i]) {
				va=dis[i];
				p=i;
			}
		}
		vis[p] = true;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && maps[p][i]!=inf && dis[i] > dis[p] + maps[p][i]) {
				dis[i] = dis[p] + maps[p][i];
			}
		}
	}
	return dis[1];
}

int main() {
	while(scanf("%d%d",&m,&n) != EOF) {
		init();
		for(int i=1; i<=n; i++) {
			int sum,l,x;
			scanf("%d%d%d",&sum, &l, &x);
			maps[0][i] = pri[i] = sum;
			lev[i] = l;
			for(int j=1; j<=x; j++) {
				int v,w;
				scanf("%d%d",&v, &w);
				maps[v][i] = w;
			}
		}
		/*
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				printf("%d%c",maps[i][j], j==n ? '\n':' ');
		for(int i=1; i<=n; i++)
			printf("pri=%d  lev=%d\n",pri[i], lev[i]);
		*/
		int ans=inf;
		for(int i=1; i<=n; i++) {
			memset(vis, false, sizeof(vis));
			memset(dis, inf, sizeof(dis));

			for(int j=1; j<=n; j++) {
				if(lev[i] - lev[j] > m || lev[i] < lev[j])
					vis[j] = true;
			}
			ans=min(ans, dijkstra());
			/*
			for(int i=1; i<=n; i++)
				printf("%d  ",dis[i]);
			puts("");
			*/
		}
		printf("%d\n", ans);
	}
	return 0;
}
