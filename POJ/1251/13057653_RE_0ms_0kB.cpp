#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

bool vis[1000];
int n;
int maps[1000][1000];
int dis[1000];

void init() {
	memset(vis, false, sizeof(vis));
	memset(maps, inf, sizeof(maps));
	memset(dis, inf, sizeof(dis));
}

int Prim(){
	int ans=0;
	for(int i=1; i<=n; i++) {
		dis[i] = maps[1][i];
	}
	dis[1]=0;
	vis[1] = true;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i])
				p=i;
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i] > maps[p][i])
				dis[i] = maps[p][i];
		}
	}
	return ans;
}

int main() {
	while(scanf("%d",&n), n) {
		init();
		for(int i=1; i<n; i++) {
			getchar();
			char be;
			int m;
			scanf("%c %d",&be, &m);
			for(int j=1; j<=m; j++) {
				char ch;
				int w;
				scanf(" %c %d",&ch, &w);
				maps[be-'A'+1][ch-'A'+1] = w;
				maps[ch-'A'+1][be-'A'+1] = w;
			}
		}
		for(int i=1; i<=n; i++)
			maps[i][i]=0;
/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d  ",maps[i][j]);
			}
			printf("\n");
		}
*/
		int ans=Prim();
		printf("%d\n", ans);
	}
	return 0;
}