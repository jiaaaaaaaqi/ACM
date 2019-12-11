#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int maps[1005][1005];
int dis[1005];
bool vis[1005];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
}

void dijkstra(int pos) {
	vis[pos]=true;
	for(int i=1; i<=pos; i++) {
		dis[i] = maps[pos][i];
	}
	dis[pos]=0;
	for(int r=2; r<=pos; r++) {
		int p=0;
		for(int i=1; i<=pos; i++) {
			if(!vis[i] && dis[p]>dis[i])
				p=i;
		}
		if(p==0)
			return ;
		vis[p]=true;
		for(int i=1; i<=pos; i++) {
			if(dis[i] > dis[p] + maps[p][i])
				dis[i] = dis[p] + maps[p][i];
		}
	}
}

int main() {
	int n,m;
	while(scanf("%d%d",&m, &n) != EOF) {
		init();
		while(m--) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] > w)
				maps[u][v] = maps[v][u] = w;
		}
		dijkstra(n);
		printf("%d\n", dis[1]);
	}
	return 0;
}