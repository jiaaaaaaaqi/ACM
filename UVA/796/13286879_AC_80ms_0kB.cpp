#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 10000;

struct Node {
	int u;
	int v;
	int next;
};
struct Edge{
	int u;
	int v;
}; 
Edge edge[maxn];
Node node[maxn * 10];
int head[maxn];
int dfn[maxn];
int low[maxn];
int fath[maxn];
bool vis[maxn];
bool maps[maxn][maxn];
int n, tol, cnt;

void init() {
	cnt = tol= 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(maps, 0, sizeof(maps));
	memset(fath, 0, sizeof(fath));
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa){
	fath[u] = fa;
	low[u] = dfn[u] = ++cnt;
	vis[u] = true;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		int v = node[i].v;
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void tarjan() {
	for(int u=0; u<n; u++) {
		if(!dfn[u]) {
			dfs(u, u);
		}
	}
}

bool cmp(Edge a, Edge b) {
	if(a.u == b.u)
		return a.v < b.v;
	else
		return a.u < b.u;
}

void solve() {
	tol = 0;
	for(int u=0; u<n; u++) {
		int v = fath[u];
		if(low[u] > dfn[v] && v != u) {
			edge[tol].u = u;
			edge[tol].v = v;
			if(edge[tol].u > edge[tol].v)
				swap(edge[tol].u, edge[tol].v);
			tol++;
		}
	}
	sort(edge, edge+tol, cmp);	
	printf("%d critical links\n", tol);	
	for(int i=0; i<tol; i++) {
		printf("%d - %d\n", edge[i].u, edge[i].v);
	}
	printf("\n");
}

int main() {
	while(scanf("%d", &n) != EOF) {
		init();
		if(n == 0) {
			printf("0 critical links\n\n");
			continue;
		}
		for(int i=1; i<=n; i++) {
			int u;
			int num;
			scanf("%d (%d)", &u, &num);
			for(int j=1; j<=num; j++) {
				int v;
				scanf("%d", &v);
				maps[u][v] = maps[v][u] = 1; 
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(maps[i][j]) {
					addnode(i, j);
					addnode(j, i);
				}
			}
		}
		tarjan();
		solve();
	}
	return 0;
}