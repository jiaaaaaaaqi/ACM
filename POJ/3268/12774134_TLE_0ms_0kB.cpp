#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;
int n,en;
int dis[1005][1005];
int maps[1005][1005];
bool vis[1005];

void init() {
	memset(dis, inf, sizeof(dis));
	memset(maps, inf, sizeof(maps));
}

void dijkstra(int pos) {
	memset(vis, false, sizeof(vis));
	vis[pos]=true;
	for(int i=1; i<=n; i++)
		dis[pos][i] = maps[pos][i];
	dis[pos][pos] = 0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[pos][p] > dis[pos][i])
				p=i;
		}
		vis[p]=true;
		for(int i=1; i<=n; i++) {
			if(dis[pos][i] > dis[pos][p] + maps[p][i])
				dis[pos][i] = dis[pos][p] + maps[p][i];
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
		for(int i=0; i<=n; i++) {
			dijkstra(i);
		}
/*		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				printf("%d%c",dis[i][j], j==n ? '\n':' ');
*/
		int ans=0;
		for(int i=1; i<=n; i++) {
			ans=max(ans, dis[i][en] + dis[en][i]);
		}

		printf("%d\n", ans);
	}
	return 0;
}