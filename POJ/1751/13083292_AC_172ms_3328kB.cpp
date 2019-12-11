#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node {
	int x;
	int y;
} node[800];
int maps[800][800];
bool vis[800];
int dis[800];
int pre[800];
bool used[800][800];

void init() {
	memset(used, false, sizeof(used));
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(node, 0, sizeof(node));
	memset(dis, inf, sizeof(dis));
}

void Prim(int n) {
	for(int i=1; i<=n; i++) {
		dis[i] = maps[1][i];
		pre[i] = 1;
	}
	pre[1] = 0;
	dis[1] = 0;
	vis[1] = true;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p = i;
			}
		}
		vis[p] = true;
		used[p][pre[p]] = used[pre[p]][p] = true;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i] > maps[p][i]) {
				dis[i] = maps[p][i];
				pre[i] = p;
			}
		}
	}
}

int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d%d",&node[i].x, &node[i].y);
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int x1 = node[i].x;
				int x2 = node[j].x;
				int y1 = node[i].y;
				int y2 = node[j].y;
				int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
				maps[i][j] = maps[j][i] = d;
			}
			maps[i][i] = 0;
		}
		int m;
		scanf("%d",&m);
		for(int i=1; i<=m; i++) {
			int u,v;
			scanf("%d%d",&u, &v);
			maps[u][v] = maps[v][u] = 0;
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d ",maps[i][j]);
			}
			puts("");
		}
		*/
		Prim(n);
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(used[i][j] && maps[i][j]!=0 ) {
					printf("%d %d\n",i, j);
				}
			}
		}
	}
	return 0;
}