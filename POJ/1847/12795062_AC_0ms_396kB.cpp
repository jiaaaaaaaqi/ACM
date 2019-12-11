#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

int n,be,en;
int maps[105][105];
int dis[105];
bool vis[105];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
}

void dijkstra(int pos) {
	vis[pos] = true;
	for(int i=1; i<=n; i++)
		dis[i] = maps[pos][i];
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
	while(scanf("%d%d%d",&n,&be,&en) != EOF) {
		init();
		for(int i=1; i<=n; i++) {
			int k;
			scanf("%d", &k);
			for(int j=1; j<=k; j++) {
				int v;
				scanf("%d", &v);
				if(j==1)
					maps[i][v] = 0;
				else
					maps[i][v] = 1;
			}
			maps[i][i] = 0;
		}
		/*
		for(int i=1; i<=n; i++) { 
			for(int j=1; j<=n; j++)
				printf("%d  ",maps[i][j]);
			printf("\n");
		}
		*/
		dijkstra(be);
		if(dis[en] != inf)
			printf("%d\n", dis[en]);
		else
			printf("-1\n");
	}
	return 0;
}
