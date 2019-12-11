#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;

int id[maxn],dfn[maxn],vis[maxn],dfsn,ans[maxn][maxn];
vector<int>g[maxn];
int n,ansn;

void tarjan(int u,int fa) {
	id[u]=dfn[u]=++dfsn;
	int l1=g[u].size();
	for(int i=0; i<l1; i++) {
		int v=g[u][i];
		if(v==fa) continue;
		if(!dfn[v]) {
			tarjan(v,u);
			id[u]=min(id[u],id[v]);
		} else
			id[u]=min(id[u],dfn[v]);
		if(id[v]>dfn[u]) {
			if(!ans[u][v]) {
				ans[u][v]=ans[v][u]=1,ansn++;
			}
		}
	}
}

void solve() {
	memset(id,0,sizeof(id));
	memset(dfn,0,sizeof(dfn));
	memset(ans,0,sizeof(ans));
	dfsn=ansn=0;
	for(int i=0; i<n; i++) {
		if(!vis[i])	tarjan(i,i);
	}
	printf("%d critical links\n",ansn);
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(ans[i][j]) {
				printf("%d - %d", i, j);
				printf("\n");
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