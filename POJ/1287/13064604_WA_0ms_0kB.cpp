#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn=50;
bool vis[maxn];
int maps[maxn][maxn];
int dis[maxn];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
}

int Prim(int n) {
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	dis[1] = 0;
	vis[1] = true;
	int ans=0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i])
				p=i;
		}
		ans += dis[p];
		vis[p] = true;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i] > maps[p][i])
				dis[i] = maps[p][i];
		}
	}
	return ans;
}

int main() {
	int n;
	while(scanf("%d",&n), n) {
		init();
		int m;
		scanf("%d",&m);
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] > w)
				maps[u][v] = maps[v][u] = w;
		}
		for(int i=1; i<=n; i++)
			maps[i][i] = 0;
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d ",maps[i][j]);
			}
			printf("\n");
		}
		*/
		int ans = Prim(n);
		printf("%d\n",ans);
	}
	return 0;
}