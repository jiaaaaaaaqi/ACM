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
const int maxn = 100005;
const int maxm = 1000;
using namespace std;

int n, m, tol;
struct Node{
	int u;
	int v;
	int w;
	int next;
};
Node node[maxn];
int head[maxn];
int flow[maxn];
int dep[maxn];
queue<int > q;

void init() {
	tol = 0;
	memset(dep, 0, sizeof(dep));
	memset(node, 0, sizeof(node));
	memset(flow, 0, sizeof(flow));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	while(!q.empty())	q.pop();
	memset(dep, 0, sizeof(dep));
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u == des)	return true;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(!dep[v] && node[i].w) {
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
			int tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
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
	int f, d;
	while(~scanf("%d%d%d", &n, &f, &d)) {
		init();
		int src = 0;
		int des = f + d + 2 * n + 1;
		for(int i=1; i<=f; i++) {
			int w;
			scanf("%d", &w);
			addnode(src, i, w);
			addnode(i, src, 0);
		}
		for(int i=1; i<=d; i++) {
			int w;
			scanf("%d", &w);			
			addnode(f + n + n + i, des, w);
			addnode(des, f + n + n + i, 0);
		}
		char str[250];
		for(int t=1; t<=n; t++) {
			scanf("%s", str + 1);
			for(int i=1; i<=f; i++) {
				if(str[i] == 'Y') {
					addnode(i, f + t, 1);
					addnode(f + t, i, 0);
				} else {
					continue;
				}
			}
		}
		for(int t=1; t<=n; t++) {
			scanf("%s", str + 1);
			for(int i=1; i<=d; i++) {
				if(str[i] == 'Y') {
					addnode(f + n + t, f + n + n + i, 1);
					addnode(f + n + n + i, f + n + t, 0);
				} else {
					continue;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			addnode(f + i, f + i + n, 1);
			addnode(f + i + n, f + i, 0);
		}
		int ans = dinic(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
 