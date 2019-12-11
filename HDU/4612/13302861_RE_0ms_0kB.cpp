#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 200005;
const int maxm = 1000005;
int n, m, tol, top, cnt;
int stacksize;

struct Node {
	int u;
	int v;
	int next;
	bool vis;
};
struct Edge {
	int u;
	int v;
};
Edge edge[maxn];
Node node[2 * maxm];
bool vis[maxn];
int dfn[maxn];
int low[maxn];
int point[maxn];
int stack[maxn];
int head[maxn];
int maps[maxn/100][maxn/100];

void init() {
	tol = cnt = top = stacksize = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(head, -1, sizeof(head));
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(point, 0, sizeof(point));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].vis = false;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u) {
	int v;
	vis[u] = true;
	stack[stacksize++] = u;
	dfn[u] = low[u] = ++cnt;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		v = node[i].v;
		if(node[i].vis)
			continue;
		node[i].vis = node[i^1].vis = true;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v] && node[i^1].vis) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		int v;
		do {
			v = stack[--stacksize];
			vis[v] = false;
			point[v] = top;
		} while(v != u);
	}
}

void tarjan() {
	for(int u=1; u<=n; u++) {
		if(!dfn[u]) {
			dfs(u);
		}
	}
}

void spfa() {
	int numbri=0;
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i!=-1; i=node[i].next) {
			int v = node[i].v;
			if(point[u] != point[v]) {
				numbri++;
				maps[point[u]][point[v]] = 1;
				maps[point[v]][point[u]] = 1;
			}
		}
	}
	for(int k=1; k<=top; k++) {
		for(int i=1; i<=top; i++) {
			for(int j=1; j<=top; j++) {
				maps[i][j] = min(maps[i][k]+maps[k][j], maps[i][j]);
			}
		}
	}
	int ans = inf;
	for(int i=1; i<=top; i++)
		ans = min(ans, maps[i][i]);
	
	printf("%d\n", numbri-ans);
}

int main() {
	while(scanf("%d%d",&n, &m), n||m) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addnode(u, v);
			addnode(v, u);
		}
		tarjan();
		spfa();
	}
	return 0;
}