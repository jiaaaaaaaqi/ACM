/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Thu 10 Oct 2019 04:28:29 PM CST
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
	int u, v;
	int w;
} edge[maxn];
int a[maxn];

int tot;
vector<int> vv[maxn];
int fa[maxn], sz[maxn], deep[maxn], son[maxn];
int top[maxn], id[maxn], rk[maxn];

void init() {
	tot = deep[0] = 0;
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

void dfs1(int u, int f) {
	deep[u] = deep[f]+1;
	fa[u] = f;
	sz[u] = 1;
	son[u] = 0;
	for(auto v : vv[u]) {
		if(v == f)	continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v])	son[u] = v;
	}
}

void dfs2(int u, int tp) {
	id[u] = ++tot;
	rk[tot] = u;
	top[u] = tp;
	if(!son[u])	return ;
	dfs2(son[u], tp);
	for(auto v : vv[u]) {
		if(v == fa[u] || v == son[u])	continue;
		dfs2(v, v);
	}
}

int node[maxn<<2];

void pushup(int rt) {
	node[rt] = max(node[rt<<1], node[rt<<1|1]);
}

void build(int l, int r, int rt) {
	node[rt] = 0;
	if(l == r) {
		node[rt] = a[rk[l]];
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int p, int w, int rt) {
	if(l == r) {
		node[rt] = w;
		return ;
	}
	int mid = l+r>>1;
	if(p <= mid)	update(l, mid, p, w, rt<<1);
	else	update(mid+1, r, p, w, rt<<1|1);
	pushup(rt);
}

void upd(int u, int w) {
	update(1, n, id[u], w, 1);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt];
	}
	int mid = l+r>>1;
	int ans = 0;
	if(pl<=mid)	ans = max(ans, query(l, mid, pl, pr, rt<<1));
	if(pr>mid)	ans = max(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

int qry(int x, int y) {
	int ans = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]])	swap(x, y);
		ans = max(ans, query(1, n, id[top[x]], id[x], 1));
		x = fa[top[x]];
	}
	if(x != y) {
		if(deep[x] > deep[y])	swap(x, y);
		ans = max(ans, query(1, n, id[x]+1, id[y], 1));
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<n; i++) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
			vv[edge[i].u].pb(edge[i].v);
			vv[edge[i].v].pb(edge[i].u);
		}
		dfs1(1, 0);
		dfs2(1, 1);
		for(int i=1; i<n; i++) {
			if(deep[edge[i].u] > deep[edge[i].v])
				swap(edge[i].u, edge[i].v);
			a[edge[i].v] = edge[i].w;
		}
		build(1, n, 1);
		char s[10];
		while(1) {
			scanf("%s", s+1);
			if(s[1] == 'D')	break;
			if(s[1] == 'Q') {
				int u, v;
				scanf("%d%d", &u, &v);
				ll ans = qry(u, v);
				printf("%lld\n", ans);
			} else if(s[1] == 'C') {
				int id, w;
				scanf("%d%d", &id, &w);
				upd(edge[id].v, w);
			}
		}
	}
	return 0;
}

