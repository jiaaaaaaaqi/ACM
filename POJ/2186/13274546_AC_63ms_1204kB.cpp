#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node {
	int u;
	int v;
	int next;
};
Node node[100000000];
int n, m;
int tol, cnt, top, stacksize;

int oudi[10005];
int maps[10005];
int stack[10005];
int dfn[10005];
int low[10005];
bool vis[10005];
int head[10005];

void init() {
	top = stacksize = cnt = tol = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(maps, 0, sizeof(maps));
	memset(oudi, 0, sizeof(oudi));
	memset(vis, false, sizeof(vis));
	memset(stack, 0, sizeof(stack));
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
		++top;
		do {
			v = stack[--stacksize];
			maps[v] = top;
			vis[v] = false;
		} while(v != u);
	}
}

void tarjan() {
	for(int u=1; u<=n; u++)
		if(!dfn[u])
			dfs(u);
}


int solve() {
	int flag;
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i!=-1; i=node[i].next) {
			int v = node[i].v;
			if(maps[u] != maps[v]) {
				oudi[maps[u]]++;
			}
		}
	}
	int ans = 0; 
	for(int i=1; i<=top; i++) {
		if(oudi[i] == 0) {
			ans++;
			flag = i;
		}
	}
	if(ans != 1)
		return 0;
	else {
		ans = 0;
		for(int i=1; i<=n; i++) {
			if(maps[i] == flag) {
				ans++;
			}
		}
		return ans;
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addnode(u, v);
		}
		tarjan();
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
