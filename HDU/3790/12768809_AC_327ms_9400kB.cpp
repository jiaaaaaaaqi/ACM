#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct node {
	int len;
	int cos;
};
node way[1005][1005];
int dis[1005];
int ans[1005];
bool vis[1005];
int n,m;

void init(int n) {
	memset(vis, 0, sizeof(vis));
	memset(ans, inf, sizeof(ans));
	memset(dis, inf, sizeof(dis));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			way[i][j].len = inf;
			way[i][j].cos = inf;
		}
	}
}

void dijkstra(int pos) {
	vis[pos]=1;
	for(int i=1; i<=n; i++) { 
		dis[i]=way[pos][i].len;
		ans[i]=way[pos][i].cos;
	}
	dis[pos]=0;
	ans[pos]=0;
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
			if(dis[i] > dis[p]+way[p][i].len) {
				dis[i] = dis[p] + way[p][i].len;
				ans[i] = ans[p] + way[p][i].cos;
			}
			else if(dis[i] == dis[p]+way[p][i].len) {
				if(ans[i] > ans[p] + way[p][i].cos)
					ans[i] = ans[p] + way[p][i].cos;
			}
		}
	}
}

int main() {
	while(scanf("%d%d",&n, &m), n||m) {
		init(n);
		while(m--) {
			int u,v,c,l;
			scanf("%d%d%d%d",&u, &v, &l, &c);
			if(way[u][v].len < l)
				continue;
			else if(way[u][v].len == l) {
				if(way[u][v].cos > c) {
					way[u][v].len=way[v][u].len=l;
					way[u][v].cos=way[v][u].cos=c;
				} 
				else
					continue;
			}
			else if(way[u][v].len > l) {
				way[u][v].len=way[v][u].len=l;
				way[u][v].cos=way[v][u].cos=c;
			}
		}
		int be,en;
		scanf("%d%d",&be, &en);
		dijkstra(be);
		printf("%d %d\n", dis[en], ans[en]);
	}
	return 0;
}