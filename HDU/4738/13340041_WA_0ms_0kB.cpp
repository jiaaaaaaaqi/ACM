#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1005;
const int maxm = 1005*1005;
int n, m;
int top, tol, cnt;

struct Node {
	int v;
	int next;
	int w;
};
Node node[maxm * 2];
int dfn[maxn];
int low[maxn];
int fath[maxn];
int head[maxn];

void init() {
	tol = top = cnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(fath, 0, sizeof(fath));
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa) {
	dfn[u] = low[u] = ++cnt;
	fath[u] = fa;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		int v = node[i].v;
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		top++;
	}
}

int tarjan() {
	int time = 0;
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			dfs(i, i);
			time++;
		}
	}
	return time;
}

int solve() {
	int ans = 0x3f3f3f3f;
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i!=-1; i=node[i].next) {
			int v = node[i].v;
			if(dfn[u] < low[v] && u != v) {
				ans = min(ans, node[i].w);
			}
		}
	}
	return ans;
}

int main() {
	while(scanf("%d%d",&n, &m), n||m) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, w);
		}
		int time = tarjan();
		if(time > 1)
			printf("0\n");
		else {
			int ans = solve();
			if(ans == 0x3f3f3f3f)
				printf("-1\n");
			else if(ans == 0)
				printf("1\n");
			else
				printf("%d\n", ans);	
		}
	}
	return 0;
}