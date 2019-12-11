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
const int maxn = 200;
const int maxm = 30000;
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
int K;
int cost[maxn][maxn][maxn];
int need[maxn][maxn];
int give[maxn][maxn];
int nsum[maxn];
int gsum[maxn];
int head[maxn];
int pre[maxn];
int dis[maxn];
int cap[maxn];
bool vis[maxn];

void init() {
	memset(gsum, 0, sizeof gsum);
	memset(nsum, 0, sizeof nsum);
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
	memset(dis, inf, sizeof dis);
	memset(cap, inf, sizeof cap);
	dis[src] = 0;
	vis[src] = true;
	pre[src] = src;
	cap[src] = inf;
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
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
	while(scanf("%d%d%d", &n, &m, &K), (n || m || K)) {
		init();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=K; j++) {
				scanf("%d", &need[i][j]);
				nsum[j] += need[i][j];
			}
		}
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=K; j++) {
				scanf("%d", &give[i][j]);
				gsum[j] += give[i][j];
			}
		}
		for(int k=1; k<=K; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					scanf("%d", &cost[i][j][k]);
				}
			}
		}
		bool flag = true;
		for(int i=1; i<=K; i++) {
			if(gsum[i] < nsum[i]) {
				flag = false;
				printf("-1\n");
				break;
			}
		}
		if(!flag)	continue;
		int ans = 0;
		for(int k=1; k<=K; k++) {
			tol = 0;
			memset(head, -1, sizeof head);
			int src = 0;
			int des = n + m + 2;
			for(int i=1; i<=m; i++) {
				addnode(src, i, inf, 0);
				addnode(i, src, 0, 0);
			}
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					addnode(j, m + i, give[i][k], cost[i][j][k]);
					addnode(m + i, j, 0, -cost[i][j][k]);
				}
			}
			for(int i=1; i<=n; i++) {
				addnode(m + i, des, need[i][k], 0);
				addnode(des, m + i, 0, 0);
			}
			ans += MCMF(src, des);
		}
		printf("%d\n", ans);
	}
	return 0;
}
