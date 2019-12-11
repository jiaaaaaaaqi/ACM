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
const int maxn = 1200;
const int maxm = 100000;
using namespace std;

int n, f, d;
int tol;
int flow[maxn];
int head[maxn];
int dep[maxn];
struct Node {
	int u;
	int v;
	int w;
	int next;
};
Node node[maxm];
queue<int > q;

void init() {
	tol = 0;
	memset(node, 0, sizeof(node));
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
	memset(dep, 0, sizeof(dep));
	while(!q.empty())	q.pop();
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			int w = node[i].w;
			if(!dep[v] && w) {
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
		int w = node[i].w;
		if(dep[v] == dep[src] + 1 && w) {
			int val = dfs(v, des, min(w, flow - ans));
			node[i].w -= val;
			node[i ^ 1].w += val;
			ans += val;
			if(ans == flow)	return ans;
		}
	}
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int val;
	while(bfs(src, des)) {
		val = dfs(src, des, inf);
		ans += val;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d%d", &n, &f, &d)) {
		init();
		int src = 0, des = 2 * n + f + d + 1;
		for(int i=1; i<=f; i++) {
			addnode(src, i, 1);
			addnode(i, src, 0);
		}
		for(int i=1; i<=d; i++) {
			addnode(f + 2 * n + i, des, 1);
			addnode(des, f + 2 * n + i, 0);
		}
		for(int i=1; i<=n; i++)	{
			addnode(f + i, f + n + i, 1);
			addnode(f + n + i, f + i, 0);
		}
		for(int i=1; i<=n; i++) {
			int d1, d2;
			scanf("%d%d", &d1, &d2);
			while(d1--) {
				int v;
				scanf("%d", &v);
				addnode(v, f + i, 1);
				addnode(f + i, v, 0);
			}
			while(d2--) {
				int v;
				scanf("%d", &v);
				addnode(f + n + i, f + 2 * n + v, 1);
				addnode(f + 2 * n + v, f + n + i, 0);
			}
		}
		int ans = dinic(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
