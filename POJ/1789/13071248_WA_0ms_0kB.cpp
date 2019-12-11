#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int maps[2005][2005];
int dis[2005];
bool vis[2005];
char str[2005][10];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
}

int count(int a, int b) {
	int ans=0;
	for(int i=0; i<7; i++) {
		if(str[a][i] != str[b][i])
			ans++;
	}
	return ans;
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
	while(scanf("%d", &n), n) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s",str[i]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				maps[i][j] = maps[j][i] = count(i, j);
			}
			maps[i][i] = 0;
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d  ",maps[i][j]);
			}
			puts("");
		}
		*/
		int ans=Prim(n);
		printf("%d\n", ans);
	}
	return 0;
}