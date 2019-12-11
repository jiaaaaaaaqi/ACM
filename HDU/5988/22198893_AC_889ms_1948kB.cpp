/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 12 Oct 2019 06:04:34 PM CST
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Edge {
	int s, b;
} edge[maxn];
struct Node {
	int u, v, w, next;
	double val;
} node[maxn];
int head[maxn], pre[maxn], cap[maxn];
double dis[maxn];
bool vis[maxn];

void init() {
	tol = 0;
	for(int i=0; i<=n+1; i++)	
		head[i] = -1;
}

void addnode(int u, int v, int w, double val) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].val = val;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool spfa(int src, int des, int &flow, double &cost) {
	for(int i=0; i<=n+1; i++) {
		vis[i] = 0;
		dis[i] = 1.0*inf;
	}
	queue<int> q;
	dis[src] = 0;
	cap[src] = inf;
	pre[src] = src;
	vis[src] = true;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(node[i].w && dis[v]>dis[u]+node[i].val+eps) {
				dis[v] = dis[u]+node[i].val;
				pre[v] = i;
				cap[v] = min(cap[u], node[i].w);
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(dis[des] == 1.0*inf)	return false;
	flow += cap[des];
	cost += 1.0*cap[des]*dis[des];
	int u = des;
	while(u != src) {
		node[pre[u]].w -= cap[des];
		node[pre[u]^1].w += cap[des];
		u = node[pre[u]].u;
	}
	return true;
}

double MCMF(int src, int des) {
	double cost = 0.0;
	int flow = 0;
	while(spfa(src, des, flow, cost));
	return cost;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		int src = 0, des = n+1;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &edge[i].s, &edge[i].b);
			int x = min(edge[i].s, edge[i].b);
			edge[i].s -= x;
			edge[i].b -= x;
			if(edge[i].s) {
				addnode(src, i, edge[i].s, 0);
				addnode(i, src, 0, 0);
			}
			if(edge[i].b) {
				addnode(i, des, edge[i].b, 0);
				addnode(des, i, 0, 0);
			}
		}
		for(int i=1; i<=m; i++) {
			int u, v, c;
			double p;
			scanf("%d%d%d%lf", &u, &v, &c, &p);
			p = 1.0-p;
			if(c < 1)	continue;
			addnode(u, v, 1, 0);
			addnode(v, u, 0, 0);
			double x = log2(p);
			addnode(u, v, c-1, -x);
			addnode(v, u, 0, x);
		}
		double ans = -MCMF(src, des);
		ans = pow(2.0, ans);
		printf("%.2f\n", 1.0-ans);
	}
	return 0;
}
