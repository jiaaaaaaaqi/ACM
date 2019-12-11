#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 200005;
const int maxm = 1000005;
int n, m, tol, top, cnt;
int maxdeep, pos;
int ans;
int stacksize;

struct Node {
	int u;
	int v;
	int next;
	bool vis;
};

Node edge[maxn];
Node node[2 * maxm];
bool vis[maxn];
int dfn[maxn];
int low[maxn];
int point[maxn];
int stack[maxn];
int head[maxn];
int head2[maxn];
int dep[maxn];

void init() {
	tol = cnt = top = stacksize = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(head, -1, sizeof(head));
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

void addedge(int u, int v) {
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol].vis = false;
	edge[tol].next = head[u];
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

void dfs2(int u) {
	for(int i=head[u]; i!=-1; i=node[i].next) {
		int v = node[i].v;
		if(dep[v] == -1) {
			dep[v] = dep[u] + 1;
			dfs2(v);
		}
	}
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
		memcpy(head2, head, sizeof(head));
		int t = tol;
		tol = 0;
		for(int u=1; u<=n; u++) {
			for(int i=head2[u]; i!=-1; i=node[i].next) {
				int v = node[i].v;
				if(point[u] != point[v]) {
					addedge(point[u], point[v]);
					addedge(point[v], point[u]);
				}
			}
		}
		memset(dep, -1, sizeof(dep));
		dep[1] = 0;
		dfs2(1);
		int k = 1;
		for(int i=1; i<=top; i++) {
			if(dep[k] < dep[i]) {
				k = i;
			}
		}
		memset(dep, -1, sizeof(dep));
		dep[k] = 0;
		dfs2(k);
		int ans = 0;
		for(int i=1; i<=top; i++) {
			ans = max(ans, dep[i]);
		}
		ans = top -1 - ans;
		printf("%d\n", ans);
	}
	return 0;
}