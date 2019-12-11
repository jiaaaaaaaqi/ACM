#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int dis[105];
bool vis[105];
int maps[105][105];

void init(){
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(maps, inf, sizeof(maps));
}

void dijkstra(int n) {
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	vis[1]=true;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i])
				p=i;
		}
		if(p==0)
			return ;
		vis[p]=1;
		for(int i=1; i<=n; i++) {
			if(dis[i] > dis[p]+maps[p][i])
				dis[i]=dis[p]+maps[p][i];
		}
	}
}

int main() {
	int n,m;
	while(scanf("%d%d",&n, &m), n||m) {
		init();
		while(m--) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] > w)
				maps[u][v] = maps[v][u] = w;
		}
		dijkstra(n);
		printf("%d\n", dis[n]);
	}
	return 0;
}