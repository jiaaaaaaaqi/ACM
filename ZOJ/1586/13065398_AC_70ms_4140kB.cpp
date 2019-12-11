#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int cost[1005];
int dis[1005];
int maps[1005][1005];
bool vis[1005];

void init() {
	memset(vis, false, sizeof(vis));
	memset(maps, inf, sizeof(maps));
	memset(cost, 0, sizeof(cost));
	memset(dis, inf, sizeof(dis));
}

int Prim(int n) {
	int ans=0;
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	vis[1] = true;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p=i;
			}
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i]>maps[p][i]) {
				dis[i] = maps[p][i];
			}
		} 
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &cost[i]);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &maps[i][j]);
				if(i != j) 
					maps[i][j] += cost[i] + cost[j];
			}
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d ",maps[i][j]);
			}
			puts("");
		}*/
		int ans = Prim(n);
		printf("%d\n", ans);
	}
	return 0;
}