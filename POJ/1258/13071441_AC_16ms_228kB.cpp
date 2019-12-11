#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int maps[105][105];
int dis[105];
bool vis[105];

void init() {
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(maps, inf, sizeof(maps));
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
	int n;
	while(scanf("%d",&n) != EOF) {
		init();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &maps[i][j]);
			}
		}
		int ans=Prim(n);
		printf("%d\n", ans);
	}
	return 0;
}