#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int dis[305];
int maps[305][305];
bool vis[305];

void init() {
	memset(maps, inf, sizeof(maps));
}

void spfa(int be, int en, int &ans) {
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	queue<int> q;
	vis[be]=true;
	dis[be]=0;
	q.push(be);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int v=1; v<=n; v++) {
			if(u!=be && v==be) {
				ans = min(ans, dis[u]+maps[u][v]);
			}
			if(dis[v] > dis[u] + maps[u][v]) {
				dis[v] = dis[u] + maps[u][v];
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	while(scanf("%d",&n)!=EOF) {
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				scanf("%d",&maps[i][j]);
		int ans1=inf;
		int ans2=inf;
		spfa(1, n, ans1);
		int ans=dis[n];
		spfa(n, 1, ans2);
		printf("%d\n", min(ans, ans1+ans2));
	}
	return 0;
}