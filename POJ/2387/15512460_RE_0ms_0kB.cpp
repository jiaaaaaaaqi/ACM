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
const int maxn = 1010;
const int maxm = 2010;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
struct Node{
	int v, w, cost;
	int next;
	bool operator < (Node a) const {
		return cost > a.cost;
	}
};
Node node[maxm << 1];
int dis[maxn];
int maps[maxn][maxn];
int head[maxn];
bool vis[maxn];

void init() {
	tol = 0;
	memset(vis, 0, sizeof vis);
	memset(dis, inf, sizeof dis);
	memset(node, 0, sizeof node);
	memset(head, -1, sizeof head);
	memset(maps, inf, sizeof maps);
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dijkstra() {
	priority_queue<Node> q;
	while(!q.empty())	q.pop();
	dis[n] = 0;
	Node now;
	now.v = n;
	now.cost = 0;
	q.push(now);
	while(!q.empty()) {
		now = q.top();
		q.pop();
		int u = now.v;
		if(vis[u])	continue;
		vis[u] = true;
		dis[u] = now.cost;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(vis[v])	continue;
			Node nex;
			nex.v = v;
			nex.cost = dis[u] + node[i].w;
			q.push(nex);
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		int u, v, w;
		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			maps[u][v] = min(maps[u][v], w);
			maps[v][u] = min(maps[v][u], w);
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(maps[i][j] == inf)	continue;
				addnode(i, j, maps[i][j]);
				addnode(j, i, maps[i][j]);
			}
		}
		dijkstra();
		printf("%d\n", dis[1]);
	}
	return 0;
}
