#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;
int n,en;
int dis[2][1005];
int maps[1005][1005];
bool vis[1005];

void init() {
	memset(dis, inf, sizeof(dis));
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
	int m;
	while(scanf("%d%d%d",&n,&m,&en)!=EOF) {
		init();
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(maps[u][v] > w)
				maps[u][v] = w;
		}
		dijkstra(0, en);
		arrturn();
		dijkstra(1, en);
/*
		for(int i=0; i<=1; i++)
			for(int j=1; j<=n; j++)
				printf("%d%c",dis[i][j], j==n ? '\n':' ');
*/
		int ans=0;
		for(int i=1; i<=n; i++) {
			ans=max(ans, dis[0][i] + dis[1][i]);
		}

		printf("%d\n", ans);
	}
	return 0;
}