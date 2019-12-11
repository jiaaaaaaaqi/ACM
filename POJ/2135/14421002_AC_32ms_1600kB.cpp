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
const int maxn = 1005;
const int maxm = 40010;
using namespace std;

int n, m, tol;
struct Node{
	int u;
	int v;
	int w;
	int val;
	int next;
};
Node node[maxm];
int head[maxm];
int val[maxn];
int cap[maxn];
int pre[maxn];
bool vis[maxn];

void init() {
	tol = 0;
	memset(pre, 0, sizeof pre);
	memset(cap, 0, sizeof cap);
	memset(node, 0, sizeof node);
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w, int cost) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].val = cost;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool spfa(int src, int des, int &flow, int &cost) {
	memset(vis, 0, sizeof vis);
	memset(val, inf, sizeof val);
	queue<int > q;
	val[src] = 0;
	pre[src] = 0;
	vis[src] = 1;
	cap[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(node[i].w > 0 && val[v] > val[u] + node[i].val) {
				val[v] = val[u] + node[i].val;
				pre[v] = i;
				cap[v] = min(cap[u], node[i].w);
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(val[des] == inf)	return false;
	flow += cap[des];
	cost += val[des] * cap[des];
	int u = des;
	while(u != src) {
		node[pre[u]].w -= cap[des];
		node[pre[u]^1].w += cap[des];
		u = node[pre[u]].u;
	}
	return true;
}

int MCMF(int src, int des) {
	int flow = 0;
	int cost = 0;
	while(spfa(src, des, flow, cost));
	return cost;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, 1, w);
			addnode(v, u, 0, -w);
			addnode(v, u, 1, w);
			addnode(u, v, 0, -w);
		}
		int src = 0;
		int des = n + 1;
		addnode(src, 1, 2, 0);
		addnode(1, src, 0, 0);
		addnode(n, des, 2, 0);
		addnode(des, n, 0, 0);
		int ans = MCMF(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
