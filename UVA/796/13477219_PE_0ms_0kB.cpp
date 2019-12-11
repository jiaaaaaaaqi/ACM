#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;

int id[maxn],dfn[maxn],dfsn;
bool ans[maxn][maxn];
int fath[maxn];
vector<int>g[maxn];
int n,ansn;

void tarjan(int u, int fa) {
	fath[u] = fa;
	id[u] = dfn[u] = ++dfsn;
	for(int i=0; i<g[u].size(); i++) {
		int v = g[u][i];
		if(!dfn[v]) {
			tarjan(v, u);
			id[u] = min(id[u], id[v]);
		} else if(v != fa) {
			id[u] = min(id[u], dfn[v]);
		}
	}
}

void solve() {
	memset(id,0,sizeof(id));
	memset(dfn,0,sizeof(dfn));
	memset(ans,0,sizeof(ans));
	memset(fath, 0, sizeof(fath));
	dfsn=ansn=0;
	for(int i=0; i<n; i++) {
		if(!dfn[i])	tarjan(i,i);
	}
	/*
	for(int i=0; i<n; i++) {
		printf("%d  %d\n", id[i], dfn[i]);
	}
	*/
	for(int u=0; u<n; u++) {
		int v = fath[u];
		if(id[u] > dfn[v] && v != u) {
			if(!ans[u][v]) {
				if(u < v)
					ans[u][v] = 1;
				else
					ans[v][u] = 1;
				ansn++;
			}
		}
	}
	printf("%d critical links\n",ansn);
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(ans[i][j]) {
				printf("%d - %d\n", i, j);
			}
		}
	}
	printf("\n");
}

int main() {
	while(~scanf("%d",&n)) {
		if(n==0) {
			printf("0 critical links\n");
			continue ;
		}
		for(int i=0; i<n; i++)
			g[i].clear();
		int u,l1,v;
		for(int j=0; j<n; j++) {
			scanf("%d (%d)",&u,&l1);
			for(int i=0; i<l1; i++) {
				scanf("%d",&v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		solve();
	}
	return 0;
}