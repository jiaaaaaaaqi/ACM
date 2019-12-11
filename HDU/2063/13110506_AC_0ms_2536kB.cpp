#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=510;
int uN, vN;
int maps[maxn][maxn];
int linker[maxn];
bool vis[maxn];

void init() {
	memset(maps, 0, sizeof(maps));
	memset(linker, 0, sizeof(linker));
}

bool dfs(int u) {
	for(int v=1; v<=vN; v++) {
		if(maps[u][v] && !vis[v]) {
			vis[v] = true;
			if(!linker[v] || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	int ans = 0;
	for(int u=1; u<=uN; u++) {
		memset(vis, false, sizeof(vis));
		if(dfs(u)) {
			ans++;
		}
	}
	return ans;
}

int main() {
	int n;
	while(scanf("%d",&n), n) {
		init();
		scanf("%d%d", &uN, &vN);
		for(int i=0; i<n; i++) {
			int u,v;
			scanf("%d%d", &u, &v);
			maps[u][v] = 1;
		}
		int ans=hungary();
		printf("%d\n", ans);
	}
}