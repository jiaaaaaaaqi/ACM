#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int dis[2][1000005];
int maps[1000005][1000005];
bool vis[1000005];

void init() {
	memset(vis, inf, sizeof(vis));
	memset(maps, inf, sizeof(maps));
}


void dijkstra(int state,int pos) {
	memset(vis, false, sizeof(vis));
	vis[pos]=true;
	for(int i=1; i<=n; i++) { 
		dis[state][i] = maps[pos][i];
	} 
	dis[state][pos] = 0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[state][p] > dis[state][i])
				p=i;
		}
		vis[p]=true;
		for(int i=1; i<=n; i++) {
			if(dis[state][i] > dis[state][p] + maps[p][i])
				dis[state][i] = dis[state][p] + maps[p][i];
		}
	}
}

void arrturn() {
	int tmp;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			tmp=maps[j][i];
			maps[j][i]=maps[i][j];
			maps[i][j]=tmp;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int m;
		scanf("%d%d",&n, &m);
		init();
		while(m--) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] > w)
				maps[u][v] = w;
		}
		dijkstra(0, 1);
		arrturn();
		dijkstra(1, 1);
/*
		for(int i=0; i<=1; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d%c",dis[i][j], j==n ? '\n':' ');
			}
		}
*/
		int ans=0;
		for(int i=1; i<=n; i++)
			ans+=(dis[0][i] + dis[1][i]);
		printf("%d\n", ans);
	}
	return 0;
}
