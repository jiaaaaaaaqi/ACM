#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int busy[205];
int maps[205][205];
int dis[205];
bool vis[205];

void init() {
	memset(busy, 0, sizeof(busy));
	memset(maps, inf, sizeof(maps));
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
}

void dijkstra() {
	vis[1] = true;
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	dis[1] = 0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p] > dis[i]) {
				p=i;
			}
		}
		vis[p] = true;
		for(int i=1; i<=n; i++) {
			if(dis[i] > dis[p] + maps[p][i]) {
				dis[i] = dis[p] + maps[p][i];
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int cas=1;
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			maps[i][i] = 0;
		for(int i=1; i<=n; i++)
			scanf("%d", &busy[i]);
		int k;
		scanf("%d", &k);
		while(k--) {
			int u,v;
			scanf("%d%d",&u, &v);
			maps[u][v] = max(0, (busy[v]-busy[u])*(busy[v]-busy[u])*(busy[v]-busy[u]));
		}
		/*
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				printf("%d  ",maps[i][j]);
			printf("\n");
		}
		*/
		dijkstra();
		printf("Case %d:\n", cas++);
		scanf("%d",&k);
		while(k--) {
			int v;
			scanf("%d",&v);
			if(dis[v] == inf || dis[v] < 3) {
				printf("?\n");
			}
			else
				printf("%d\n", dis[v]);
		}
	}
	return 0;
}
