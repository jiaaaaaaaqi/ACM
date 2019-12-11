#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node {
	int u;
	int v;
	int next;
};
int n;
int tol;
int top;
int cnt;
int stacksize;
Node node[10050];
int head[105];
bool vis[105];
int dfn[105];
int low[105];
int stack[105];
int maps[105];
int indi[105];
int outdi[105];

void init() {
	tol = 0;
	top = 0;
	cnt = 0;
	stacksize = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, false, sizeof(vis));
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol;
	tol++;
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	stack[stacksize++] = u;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		v = node[i].v;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		do {
			v = stack[--stacksize];
			maps[v] = top;
			vis[v] = false;
		} while(v != u);
	}
}

void tarjan() {
	dfs(1);
}

void solve() {
	if(top == 1) {
		printf("1\n0\n");
		return ;
	}
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i!=-1; i=node[i].next) {
			int v = node[i].v;
			if(maps[u] != maps[v]) {
				indi[maps[v]]++;
				outdi[maps[u]]++;
			}
		}
	}
	int ind = 0;
	int oud = 0;
	for(int i=1; i<=top; i++) {
		if(indi[i] == 0) {
			ind ++;
		}
		if(outdi[i] == 0) {
			oud ++;
		}
	}
	int ans = max(ind, oud);
	printf("%d\n", ind);
	printf("%d\n", ans);
}

int main() {
	while(scanf("%d", &n) != EOF) {
		init();
		for(int u=1; u<=n; u++) {
			int v;
			while(scanf("%d", &v), v) {
				addnode(u, v);
			}
		}
		tarjan();
		solve();
	}
	return 0;
}