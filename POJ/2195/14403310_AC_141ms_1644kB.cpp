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
const int maxn = 205;
const int maxm = 100005;
using namespace std;

int n, m, tol;
char maps[maxn][maxn];
int d[maxm];
int a[maxm];
int pre[maxm];
int head[maxn];
bool vis[maxm];
struct Node {
	int u;
	int v;
	int w;
	int val;
	int next;
};
Node node[maxm << 2];
struct Edge {
	int x;
	int y;
};
Edge be[maxm], en[maxm];

void init() {
	tol = 0;
	memset(maps, 0, sizeof(maps));
	memset(head, -1, sizeof(head));
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
	queue<int > q;
	memset(d, inf, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[src] = 0;
	pre[src] = 0;
	vis[src] = 1;
	a[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(node[i].w > 0 && d[v] >
			        d[u] + node[i].val) {
				d[v] = d[u] + node[i].val;
				pre[v] = i;
				a[v] = min(a[u], node[i].w);
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(d[des] == inf)	return false;
	flow += a[des];
	cost += d[des] * a[des];
	int u = des;
	while(u != src) {
		node[pre[u]].w -= a[des];
		node[pre[u]^1].w += a[des];
		u = node[pre[u]].u;
	}
	return true;
}

int MCMF(int src, int des) {
	int cost = 0;
	int flow = 0;
	while(spfa(src, des, flow, cost));
	return cost;
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		int N1 = 0;
		int N2 = 0;
		for(int i=1; i<=n; i++) {
			scanf("%s", maps[i] + 1);
			for(int j=1; j<=m; j++) {
				if(maps[i][j] == 'm') {
					N1++;
					be[N1].x = i;
					be[N1].y = j;
				} else if(maps[i][j] == 'H') {
					N2++;
					en[N2].x = i;
					en[N2].y = j;
				}
			}
		}
		int src = 0;
		int des = N1 + N2 + 1;
		for(int i=1; i<=N1; i++) {
			addnode(src, i, 1, 0);
			addnode(i, src, 0, 0);
			for(int j=1; j<=N2; j++) {
				int x = abs(be[i].x - en[j].x) + abs(be[i].y - en[j].y);
				addnode(i, j+N1, 1, x);
				addnode(j+N1, i, 0, -x);
			}
		}
		for(int j=1; j<=N2; j++) {
			addnode(j+N1, des, 1, 0);
			addnode(des, j+N1, 0, 0);
		}
		int ans = MCMF(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
