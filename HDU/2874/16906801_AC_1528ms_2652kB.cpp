#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, q;
int cas, tol, T;

struct Node{
	int v, w;
	int next;
} node[maxn << 1];
int vis[maxn];
int ind[maxn];
ll dis[maxn];
int deep[maxn];
int head[maxn];
int fa[maxn][20];

void init() {
	tol = 1;
	mes(fa, 0);
	mes(ind, 0);
	mes(vis, 0);
	mes(deep, 0);
	mes(head, -1);
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int d, int cnt) {
	deep[u] = d;
	vis[u] = cnt;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(fa[v][0])	continue;
		fa[v][0] = u;
		dis[v] = dis[u] + node[i].w;
		dfs(v, d+1, cnt);
	}
}

void update() {
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			fa[i][j] = fa[fa[i][j-1]][j-1];
		}
	}
}

int lca(int u, int v) {
	if(deep[u] < deep[v])	swap(u, v);
	int f = deep[u] - deep[v];
	for(int i=0; (1<<i)<=f; i++) {
		if(f & (1<<i)) {
			u = fa[u][i];
		}
	}
	if(u != v) {
		for(int i=(int)log2(n); i>=0; i--) {
			if(fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		u = fa[u][0];
	}
	return u;
}

int main() {
	while(~scanf("%d%d%d", &n, &m, &q)) {
		init();
		int u, v, k;
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &k);
			addnode(u, v, k);
			addnode(v, u, k);
			ind[v]++;
		}
		int cnt = 1;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && !ind[i]) {
				fa[i][0] = i;
				dis[i] = 0;
				dfs(i, 1, cnt);
				cnt++;
			}
		}
		update();
		while(q--) {
			scanf("%d%d", &u, &v);
			if(vis[u] != vis[v]) {
				printf("Not connected\n");
			}
			else {
				int x = lca(u, v);
				ll ans = dis[u] + dis[v] - 2*dis[x];
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
