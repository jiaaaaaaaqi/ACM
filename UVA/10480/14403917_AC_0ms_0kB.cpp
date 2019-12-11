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
const int maxn = 55;
const int maxm = 25005;
using namespace std;

int n, m, tol;
struct Node {
	int u;
	int v;
	int w;
	int next;
};
Node node[maxm << 1];
int head[maxn];
int dep[maxn];
int res[maxm][2];
bool vis[maxn];

void init() {
	tol = 0;
	memset(res, 0, sizeof(res));
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].u = u;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	queue<int> q;
	memset(dep, -1, sizeof(dep));
	dep[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i = head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(dep[v] == -1 && node[i].w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int i=head[src]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[src] + 1 && node[i].w) {
			int tmp = dfs(v, des, min(flow - ans, node[i].w));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	if(!ans)	dep[src] = -2;
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int tmp;
	while(bfs(src, des)) {
		while((tmp = dfs(src, des, inf)) > 0) {
			ans += tmp;
		}
	}
	return ans;
}

void DFS(int u) {
	vis[u] = true;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(vis[v] || node[i].w <= 0)	continue;
		DFS(v);
	}
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		for(int i=0; i<m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, w);
			res[i][0] = u;
			res[i][1] = v;
		}
		int src = 1;
		int des = 2;
		dinic(src, des);
		DFS(src);
		for(int i=0; i<tol; i++) {
			int u = res[i][0];
			int v = res[i][1];
			if(u > v)	swap(u, v);
			if((vis[u] && !vis[v]) || (!vis[u] && vis[v])) {
				printf("%d %d\n", u, v);
			}
		}
		printf("\n");
	}
	return 0;
}
