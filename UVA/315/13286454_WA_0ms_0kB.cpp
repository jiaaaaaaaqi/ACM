#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 105;
struct Node {
	int u;
	int v;
	int next;
};
Node node[maxn * maxn * 2];
int n, tol, cnt;
int stacksize;
int dfn[maxn];
int low[maxn];
bool ans[maxn];
bool vis[maxn];
int fath[maxn];
int head[maxn];
int stack[maxn];

void init() {
	cnt = tol = stacksize = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(ans, 0, sizeof(ans));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(fath, 0, sizeof(fath));
	memset(head, -1, sizeof(head));
	memset(stack, 0, sizeof(stack));
}

void addnode(int u, int v){
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa){
	dfn[u] = low[u] = ++cnt;
	stack[stacksize++] = u;
	fath[u] = fa;
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

void tarjan(){
	dfs(1, 0);
}

int solve() {
	bool root=0;
	int sum = 0;
	for(int i=2; i<=n; i++) {
		int u = fath[i];
		if(u == 1)
			root++;
		else if(low[i] >= dfn[u]){
			ans[u] = true;
		}
	}
	if(root > 1)
		sum = 1;
	for(int i=2; i<=n; i++) {
		if(ans[i])
			sum++;
	}
	return sum;
}

int main() {
	while(scanf("%d", &n), n) {
		init();
		int u;
		while(scanf("%d", &u), u) {
			int v;
			char ch;
			while(1) {
				scanf("%d%c", &v, &ch);
				addnode(u, v);
				addnode(v, u);
				if(ch == '\n')
					break;
			}
		}
		tarjan();
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
