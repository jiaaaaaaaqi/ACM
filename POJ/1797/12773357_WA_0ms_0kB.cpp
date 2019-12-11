#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int dis[1005];
bool vis[1005];
int maps[1005][1005];

void init() {
	memset(dis, inf, sizeof(dis));
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
}

void dijkstra(int pos) {
	vis[pos]=true;
	for(int i=1; i<=n; i++) {
		dis[i] = maps[pos][i];
	}
	dis[pos]=0;
	dis[0]=0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]<dis[i]) {
				p=i;
			}
		}
		vis[p]=true;
		for(int i=1; i<=n; i++) {
			if(dis[i] < min(dis[p], maps[p][i]))
				dis[i] = min(dis[p], maps[p][i]);
		}
	}
}

int main() {
	int cas=1;
	int T;
	scanf("%d", &T); 
	while(T--) {
		init();
		int m;
		scanf("%d%d",&n, &m);
		for(int i=0; i<m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] = maps[v][u] > w)
				maps[u][v] = maps[v][u] = w;
		}
		dijkstra(1);
		printf("Scenario #%d:\n", cas++);
		printf("%d\n", dis[n]);
	}
	return 0;
}