#include<map>
#include<set>
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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
const int maxm = 400;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
struct Node {
	int u;
	int v;
	int w;
	int val;
	int next;
};
Node node[maxn];
struct Edge{
	int l;
	int r;
	int w;
	bool operator< (Edge a) const {
		return l < a.l;
	}
};
Edge edge[maxn];
int head[maxn];
int cap[maxn];
int dis[maxn];
int pre[maxn];
bool vis[maxn];
int a[maxn];

void init() {
	tol = 0;
	memset(a, 0, sizeof a);
	memset(node, 0, sizeof node);
	memset(head, -1, sizeof head);
}

void addnode(int u, int v, int w, int val) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].val = val;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool spfa(int src, int des, int &flow, int &cost) {
	memset(pre, 0, sizeof pre);
	memset(dis, inf, sizeof dis);
	memset(cap, inf, sizeof cap);
	memset(vis, false, sizeof vis);
	queue<int > q;
	pre[src] = src;
	vis[src] = true;
	dis[src] = 0;
	cap[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(node[i].w && dis[v] > dis[u] + node[i].val) {
				dis[v] = dis[u] + node[i].val;
				cap[v] = min(cap[u], node[i].w);
				pre[v] = i;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(dis[des] == inf)	return false;
	flow += cap[des];
	cost += cap[des] * dis[des];
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
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		int nn = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d", &edge[i].l, &edge[i].r, &edge[i].w);
			a[++nn] = edge[i].l;
			a[++nn] = edge[i].r;
		}
		sort(edge+1, edge+1+n);
		sort(a+1, a+1+nn);
		nn = unique(a+1, a+1+nn) - (a+1);
		int mi = inf, ma = -inf;
		for(int i=1; i<=n; i++) {
			edge[i].l = lower_bound(a+1, a+1+nn, edge[i].l) - a;
			mi = min(mi, edge[i].l);
			ma = max(ma, edge[i].l);
			edge[i].r = lower_bound(a+1, a+1+nn, edge[i].r) - a;
			mi = min(mi, edge[i].r);
			ma = max(ma, edge[i].r);
		}
		int src = mi-1;
		int des = ma+1;
		addnode(src, mi, m, 0);
		addnode(mi, src, 0, 0);
		addnode(ma, des, m, 0);
		addnode(des, ma, 0, 0);
		for(int i=mi; i<ma; i++) {
			addnode(i, i+1, inf, 0);
			addnode(i+1, i, 0, 0);
		}
		for(int i=1; i<=n; i++) {
			addnode(edge[i].l, edge[i].r, 1, -edge[i].w);
			addnode(edge[i].r, edge[i].l, 0, edge[i].w);
		}
		/*
		for(int i=0; i<tol; i++) {
			printf("%d %d %d %d\n", node[i].u, node[i].v, node[i].w, node[i].val);
		}
		*/
		int ans = -MCMF(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
