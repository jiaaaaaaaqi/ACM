#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 20005;
const int maxm = 1000;
using namespace std;

int n, m, tol;
struct Node {
	int v;
	int w;
	int next;
};
Node node[maxn << 1];
int head[maxn];
int dep[maxn];

void init() {
	tol = 0;
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	queue<int > q;
	memset(dep, 0, sizeof(dep));
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();	q.pop();
		if(u == des)	return true;
		for(int i = head[u]; ~i; i = node[i].next) {
			int v = node[i].v;
			if(!dep[v] && node[i].w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs(int u, int des, int flow) {
	if(u == des)	return flow;
	int ans = 0;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[u] + 1 && node[i].w) {
			int tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	if(!ans)	dep[u] = -1;
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	while(bfs(src, des)) {
		ans += dfs(src, des, inf);
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		int src, des;
		scanf("%d%d", &src, &des);
		des += n;
		int u, v, w;
		for(int i=1; i<=n; i++) {
			scanf("%d", &w);
			addnode(i, i+n, w);
			addnode(i+n, i, 0);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &u, &v);
			addnode(u+n, v, inf);
			addnode(v, u+n, 0);
			addnode(v+n, u, inf);
			addnode(u, v+n, 0);
		}
		printf("%d\n", dinic(src, des));
	}
	return 0;
}
