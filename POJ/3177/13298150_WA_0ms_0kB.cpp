#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n, m, tol, cnt, top;
int stacksize;
const int maxn = 5005;
const int maxm = 10000;

struct Node{
	int u;
	int v;
	int next;
};
Node node[maxm * 2];
int head[maxn];
int stack[maxn];
int dfn[maxn];
int low[maxn];
int degree[maxn]; 
int fath[maxn];
int point[maxn];

void init() {
	top = tol = cnt = stacksize = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low)); 
	memset(node, 0, sizeof(node));
	memset(fath, 0, sizeof(fath));
	memset(head, -1, sizeof(head));
	memset(stack, 0, sizeof(stack));
	memset(point, 0, sizeof(point));
	memset(degree, 0, sizeof(degree));
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa) {
	int v;
	stack[stacksize++] = u;
	fath[u] = fa;
	dfn[u] = low[u] = ++cnt;
	for(int i=head[u]; i!=-1; i=node[i].next) {
		v = node[i].v;
		if(!dfn[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++; 
		do{
			v = stack[--stacksize];
			point[v] = top;
		} while(v != u);
	}
}

void tarjan() {
	for(int u=1; u<=n; u++) {
		if(!dfn[u]) {
			dfs(u, u);
		}
	}
}

void getdegree() {
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; i!=-1; i=node[i].next) {
			int v = node[i].v;
			if(point[u] != point[v]) {
				degree[point[u]]++;
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=top; i++) {
		if(degree[i] == 1) {
			ans++;
		}
	}
	printf("%d\n", (ans+1)/2);
}

int main() {
	while(scanf("%d%d",&n, &m) != EOF) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d",&u, &v);
			addnode(u, v);
			addnode(v, u);
		}
		tarjan();
		getdegree();
	}
	return 0;
}

