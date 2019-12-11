#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100000;
const int maxm = 200000;
int n, m, tol, cnt;
int brinum;

struct Node {
	int u;
	int v;
	int next;
};
Node node[2 * maxm];
int dfn[maxn];
int low[maxn];
int fath[maxn];
int head[maxn];
bool vis[maxn];
bool bridge[maxn];

void init() {
	brinum = tol = cnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(node, 0, sizeof(node));
	memset(fath, 0, sizeof(fath));
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(bridge, 0, sizeof(bridge));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa) {
	dfn[u] = low[u] = ++cnt;
	fath[u] = fa;
	for(int i=head[u]; i != -1; i=node[i].next) {
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
	dfs(1, 1);
}

void findbridge() {
	for(int v=1; v<=n; v++) {
		int u = fath[v];
		if(dfn[u] < low[v] && u != v) {
			bridge[v] = true;
			brinum++;
		}
	}
}

void LCA(int u, int v) {
	while(dfn[u] > dfn[v]) {
		if(bridge[u]) {
			brinum--;
			bridge[u] = false;
		}
		u = fath[u];
	}
	while(dfn[v] > dfn[u]) {
		if(bridge[v]) {
			brinum--;
			bridge[v] = false;
		}
		v = fath[v];
	}
	while(u != v) {
		if(bridge[u]) {
			bridge[u] = false;
			brinum--;
		}
		if(bridge[v]) {
			bridge[v] = false;
			brinum--;
		}
		u = fath[u];
		v = fath[v];
	}
	printf("%d\n", brinum);
}

int main() {
	int cas = 1;
	while(scanf("%d%d",&n, &m), n||m) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addnode(u, v);
		}
		tarjan();
		findbridge();
		int q;
		printf("Case %d:\n", cas++);
		scanf("%d", &q);
		for(int i=1; i<=q; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			LCA(u, v);
		}
		puts("");
	}
	return 0;
}
