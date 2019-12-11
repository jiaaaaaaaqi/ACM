#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int dis[105];
int maps[105][105];
bool vis[105];

void dijkstra(int pos) {
	vis[pos]=true;
	for(int i=1; i<=n; i++)
		dis[i] = maps[pos][i];
	dis[pos]=0;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p] > dis[i])
				p=i;
		}
		vis[p]=true;
		for(int i=1; i<=n; i++) {
			if(dis[i] > dis[p] + maps[p][i]) {
				dis[i] = dis[p] + maps[p][i];
			}
		}
	}
}

void init() {
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(maps, inf, sizeof(maps));
}

int main() {
	while(scanf("%d", &n) != EOF) {
		init();
		for(int i=1; i<=n; i++)
			maps[i][i] = 0;
		char ch[20]={0};
		
		for(int i=2; i<=n; i++) {
			for(int j=1; j<i; j++) {
				int ans=0;
				memset(ch, 0, sizeof(ch));
				scanf("%s", ch);
				if(ch[0] == 'x')
					continue;
				else {
					for(int k=0; ch[k]!='\0'; k++)
						ans=ans*10+(ch[k]-'0');
					maps[i][j] = maps[j][i] = ans;
				}
			}
		}
/*	
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				printf("%d%c",maps[i][j], j==n ? '\n':'\t');
		}
*/		
		dijkstra(1);
/*
		for(int i=1; i<=n; i++)
			printf("%d ",dis[i]);
*/
		int ans=0;
		for(int i=1; i<=n; i++)
			ans=max(ans, dis[i]);
		printf("%d\n", ans);
	}
	return 0;
}