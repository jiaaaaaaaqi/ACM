#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

bool used[105][105];
bool vis[105];
int maps[105][105];
int dis[105];
int pre[105];
int cost[105][105];

void init(int n) {
	memset(used, false, sizeof(used));
	memset(vis, false, sizeof(vis));
	memset(maps, inf, sizeof(maps));
	memset(cost, 0, sizeof(cost));
	memset(dis, inf, sizeof(dis));
}

int Prim(int n) {
	int ans=0;
	vis[1] = true;
	for(int i=1; i<=n; i++) {
		pre[i] = 1;
		dis[i] = maps[1][i];
	}
	dis[1] = 0;
	pre[1] = 0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p=i;
			}
		}
		if(p == 0)
			return -1;
		vis[p] = true;
		ans += dis[p];
		used[p][pre[p]] = used[pre[p]][p] = true;
		for(int i=1; i<=n; i++) {
			if(vis[i])
				cost[p][i] = cost[i][p] = max(cost[i][pre[p]], dis[p]);
			if(!vis[i] && dis[i]>maps[p][i]) {
				dis[i] = maps[p][i];
				pre[i] = p;
			}
		}
	}
	return ans;
}

int find(int n, int ans) {
	int MIN=inf;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(maps[i][j] != inf && !used[i][j]) {
		//		printf("%d  %d\n",maps[i][j], cost[i][j]);
				MIN = min(MIN, ans - cost[i][j] + maps[i][j]);
			}
		}
	}
	return MIN;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m;
		scanf("%d%d", &n, &m);
		init(n);
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d%d%d",&u, &v, &w);
			if(maps[u][v] > w)
				maps[u][v] = maps[v][u] = w;
		}
		for(int i=1; i<=n; i++)
			maps[i][i] = 0;
		int MST=Prim(n);
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d  ",used[i][j]);
			}
			puts("");
		}
		*/
		if(MST == -1) {
			printf("Not Unique!\n");
			continue;
		}
		int SECMST=find(n, MST);
		if(MST == SECMST)
			printf("Not Unique!\n");
		else
			printf("%d\n", MST);
	}
	return 0;
}