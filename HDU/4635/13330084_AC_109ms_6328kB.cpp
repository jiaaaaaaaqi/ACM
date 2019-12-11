#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100005;
const int maxm = 100005;
int n, m;
int top, tol, cnt;
int stacksize;

struct Node{
	int u;
	int v;
	int next;
};
Node node[maxm];
int dfn[maxn];
int low[maxn];
int vis[maxn];
int num[maxn];
int indi[maxn];
int oudi[maxn];
int head[maxn];
int stack[maxn];
int point[maxn];

void init() {
	tol = top = stacksize = cnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(num, 0, sizeof(num));
	memset(indi, 0, sizeof(indi));
	memset(oudi, 0, sizeof(oudi)); 
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(point, 0, sizeof(point));
	memset(stack, 0, sizeof(stack));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	stack[stacksize++] = u;
	vis[u] = true;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		v = node[i].v;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		top++;
		do{
			v = stack[--stacksize];
			vis[v] = false;
			num[top]++;
			point[v] = top;
		} while(v != u);
	}
}

void tarjan() {
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			dfs(i);
		}
	}
}

int solve() {
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i+1; i=node[i].next) {
			int v = node[i].v;
			if(point[u] != point[v]) {
				oudi[point[u]]++;
				indi[point[v]]++;
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=top; i++) {
		if(!oudi[i] || !indi[i]) {
			ans = max(ans, n*n-n-m-(n-num[i])*num[i]);
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addnode(u, v);
		}
		tarjan();
		if(top == 1) {
			printf("Case %d: -1\n", cas++);
		} else {
			int ans = solve();
			printf("Case %d: %d\n", cas++, ans);
		}
	}
}