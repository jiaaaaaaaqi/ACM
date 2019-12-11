/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月31日 星期六 10时06分11秒
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
const int    maxn = 4e3 + 100;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
struct Node {
	int u, v, w;
	int val;
	int next;
} node[maxm];
int pre[maxn], dis[maxn], cap[maxn], head[maxn];
bool vis[maxn];

void init() {
	tol = 0;
	mes(head, -1);
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
	mes(pre, 0), mes(dis, inf), mes(cap, inf), mes(vis, 0);
	queue<int> q;
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
			if(node[i].w && dis[v]>dis[u]+node[i].val) {
				dis[v] = dis[u]+node[i].val;
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
	cost += cap[des]*dis[des];
	int u = des;
	while(u != src) {
		node[pre[u]].w -= cap[des];
		node[pre[u]^1].w += cap[des];
		u = node[pre[u]].u;
	}
	return true;
}

int MCMF(int src, int des) {
	int flow = 0, cost = 0;
	while(spfa(src, des, flow, cost));
	return cost;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		int src = n+n+1, ssrc = n+n+2;
		int des = n+n+4, ddes = n+n+3;
		addnode(src, ssrc, m, 0);
		addnode(ssrc, src, 0, 0);
		addnode(ddes, des, m, 0);
		addnode(des, ddes, 0, 0);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		for(int i=1; i<=n; i++) {
			addnode(ssrc, i, 1, -a[i]);
			addnode(i, ssrc, 0, a[i]);
			addnode(i, i+n, 1, 0);
			addnode(i+n, i, 0, 0);
			for(int j=i+1; j<=n; j++) {
				if(a[i] <= a[j]) {
					addnode(i+n, j, 1, -a[j]);
					addnode(j, i+n, 0, a[j]);
				}
			}
			addnode(i+n, ddes, 1, 0);
			addnode(ddes, i+n, 0, 0);
		}
		int ans = MCMF(src, des);
		printf("%d\n", -ans);
	}
    return 0;
}

