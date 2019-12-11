#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 200005;
const int maxm = 1000005;
int n, m, tol, top, cnt;
int maxdeep, pos;
int bridge;
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

void init() {
	tol = cnt = top = stacksize = 0;
	bridge = 0;
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
	edge[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u) {
	int v;
	low[u] = dfn[u] = ++cnt;
	vis[u] = true;
	stack[stacksize++] = u;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		v=node[i].v;
		if(node[i].vis)
			continue;
		node[i].vis = node[i^1].vis = true;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u],low[v]);
			if(dfn[u] < low[v])
				bridge++;
		} else if(vis[v]) {
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

void dfs2(int u, int pre, int deep) {
	vis[u] = true;
	if(deep > maxdeep) {
		maxdeep = deep;
		pos = u;
	}
	for(int i=head[u]; i!=-1; i=edge[i].next) {
		int v = edge[i].v;
		if(!vis[v]) {
			dfs2(v, u, deep+1);
		}
	}
}

int main() {
	while(scanf("%d%d",&n, &m) != EOF) {
		if(n==0 || m==0)
			break;
		init();
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(u == v)
				continue;
			addnode(u, v);
			addnode(v, u);
		}
		tarjan();
		memcpy(head2, head, sizeof(head));
		memset(head, -1, sizeof(head));
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
		/*
		for(int i=0; i<tol; i++)
			printf("!!%d  %d\n",edge[i].u, edge[i].v);
		*/
		maxdeep = pos = 0;
		memset(vis, false, sizeof(vis));
		vis[1] = true;
		dfs2(1, 1, 0);
		memset(vis, false, sizeof(vis));
		vis[pos] = true;
		maxdeep = 0;
		dfs2(pos, pos, 0);
		int ans = bridge - maxdeep;
		printf("%d\n", ans);
	}
	return 0;
}