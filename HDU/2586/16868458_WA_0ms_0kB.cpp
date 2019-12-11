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
const int    maxn = 4e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int v, d;
	int next;
} node[maxn << 1];
int vis[maxn];
int dis[maxn];
int head[maxn];
int deep[maxn];
int fa[maxn][30];

void init() {
	tol = 1;
	mes(fa, 0);
	mes(vis, 0);
	mes(dis, 0);
	mes(deep, 0);
	mes(head, -1);
}

void addnode(int u, int v, int d) {
	node[tol].v = v;
	node[tol].d = d;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int f, int d) {
	deep[u] = d;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		int d = node[i].d;
		if(f == v)		continue;
		if(fa[v][0])	continue;
		fa[v][0] = u;
		dis[v] = dis[u] + d;
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
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<n; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, w);
		}
		int d;
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				d = i;
				break;
			}
		}
		fa[d][0] = d;
		dfs(d, d, 1);
		update();
//		for(int i=1; i<=n; i++)
//			printf("!!!%d %d %d\n", i, fa[i][0], dis[i]);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int x = lca(u, v);
			int ans = abs(dis[x] - dis[u]) + abs(dis[x] - dis[v]);
			printf("%d\n", ans);
		}
		printf("\n");
	}
	return 0;
}
