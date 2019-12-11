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

int n, m, q;
int cas, tol, T;

struct Node{
	int v, w;
	int next;
} node[maxn << 1];
int fa[maxn];
ll dis[maxn];
ll ans[maxn];
bool vis[maxn];
int head[maxn];
vector< pii > vec[maxn];

void init() {
	tol = 1;
	mes(vis, 0);
	mes(dis, 0);
	mes(ans, 0);
	mes(head, -1);
	for(int i=1; i<=n; i++) {
		fa[i] = i;
		vec[i].clear();
	}
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(x != y) {
		fa[y] = x;
	}
}

void dfs(int u, int f, ll d) {
	dis[u] = d;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(v == f)	continue;
		dfs(v, u, d+node[i].w);
		bind(u, v);
	}
	vis[u] = 1;
	int len = vec[u].size();
	for(int i=0; i<len; i++) {
		int v = vec[u][i].fi;
		if(vis[v]) {
			int x = find(v);
			ans[vec[u][i].se] = dis[u] + dis[v] - 2 * dis[x];
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		int f1, f2, l;
		char d[2];
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%s", &f1, &f2, &l, d);
			addnode(f1, f2, l);
			addnode(f2, f1, l);
			vis[f2] = 1;
		}
		int q;
		scanf("%d", &q);
		for(int i=1; i<=q; i++) {
			scanf("%d%d", &f1, &f2);
			vec[f1].push_back(make_pair(f2, i));
			vec[f2].push_back(make_pair(f1, i));
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				mes(vis, 0);
				dfs(i, i, 0);
				break;
			}
		}
		for(int i=1; i<=q; i++) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
