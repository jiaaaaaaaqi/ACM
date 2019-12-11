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
const int maxn = 4200;
const int maxm = 555000;
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
int head[maxn];
int pre[maxn];
int dis[maxn];
int cap[maxn];
bool vis[maxn];
int maps[55][55];

void init() {
	tol = 0;
	memset(maps, 0, sizeof maps);
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
	memset(vis, false, sizeof vis);
	memset(pre, 0, sizeof pre);
	memset(cap, 0, sizeof cap);
	memset(dis, inf, sizeof dis);
	pre[src] = src;
	vis[src] = true;
	cap[src] = inf;
	dis[src] = 0;
	queue<int > q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; ~i; i = node[i].next) {
			int v = node[i].v;
			if(dis[v] > dis[u] + node[i].val && node[i].w) {
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
	if(dis[des] == inf)		return false;
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
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		int src = 0;
		int des = n + n * m + 1;
		for(int i=1; i<=n; i++) {
			addnode(src, i, 1, 0);
			addnode(i, src, 0, 0);
			for(int j=1; j<=m; j++) {
				scanf("%d", &maps[i][j]);
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				for(int k=1; k<=n; k++) {
					addnode(i, j * n + k, 1, k * maps[i][j]);
					addnode(j * n + k, i, 0, -(k * maps[i][j]));
				}
			}
		}
		for(int i=1; i<=n*m; i++) {
			addnode(n + i, des, 1, 0);
			addnode(des, n + i, 0, 0);
		}
		int ans = MCMF(src, des);
		double res = (double)ans / n;
		printf("%.6f\n", res);
	}
	return 0;
}
