/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 09 Oct 2019 11:11:25 PM CST
 ***************************************************************/
#pragma comment(linker, “/STACK:1024000000,1024000000”
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

int a[maxn];
vector<int> vv[maxn];
int fa[maxn], sz[maxn], son[maxn], deep[maxn];
int top[maxn], id[maxn], rk[maxn];

void init() {
	tol = 0;
	deep[0] = 0;
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

void dfs1(int u, int f) {
	fa[u] = f;
	sz[u] = 1;
	son[u] = 0;
	deep[u] = deep[f]+1;
	for(auto v : vv[u]) {
		if(v == f)	continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]])	son[u] = v;
	}
}

void dfs2(int u, int tp) {
	id[u] = ++tol;
	rk[tol] = u;
	top[u] = tp;
	if(son[u] == 0)	return ;
	dfs2(son[u], tp);
	for(auto v : vv[u]) {
		if(v==fa[u] || v==son[u])	continue;
		dfs2(v, v);
	}
}

int node[maxn<<2], lazy[maxn<<2];

void pushdown(int rt, int lnum, int rnum) {
	if(lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		node[rt<<1] += lazy[rt]*lnum;
		node[rt<<1|1] += lazy[rt]*rnum;
		lazy[rt] = 0;
	}
}

void pushup(int rt) {
	node[rt] = node[rt<<1]+node[rt<<1|1];
}

void build(int l, int r, int rt) {
	lazy[rt] = 0;
	if(l == r) {
		node[rt] = a[rk[l]];
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int pl, int pr, int w, int rt) {
	if(pl<=l && r<=pr) {
		node[rt] += (r-l+1)*w;
		lazy[rt] += w;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(pl <= mid)
		update(l, mid, pl, pr, w, rt<<1);
	if(pr > mid)
		update(mid+1, r, pl, pr, w, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int p, int rt) {
	if(l == r)	return node[rt];
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(p <= mid)	return query(l, mid, p, rt<<1);
	else	return query(mid+1, r, p, rt<<1|1);
}

void upd(int x, int y, int w) {
	while(top[x] != top[y]) {
		if(deep[x] < deep[y])	swap(x, y);
		update(1, n, id[top[x]], id[x], w, 1);
		x = fa[top[x]];
	}
	if(id[x] > id[y])	swap(x, y);
	update(1, n, id[x], id[y], w, 1);
}

int qry(int x) {
	return query(1, n, id[x], 1);
}

int main() {
	// freopen("in", "r", stdin);
	int p;
	while(~scanf("%d%d%d", &n, &m, &p)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			vv[u].pb(v);
			vv[v].pb(u);
		}
		dfs1(1, 1);
		dfs2(1, 1);
		build(1, n, 1);
		char s[4];
		int c1, c2, k;
		while(p--) {
			scanf("%s", s+1);
			if(s[1] == 'I') {
				scanf("%d%d%d", &c1, &c2, &k);
				upd(c1, c2, k);
			} else if(s[1] == 'D') {
				scanf("%d%d%d", &c1, &c2, &k);
				upd(c1, c2, -k);
			} else if(s[1] == 'Q') {
				scanf("%d", &c1);
				int ans = qry(c1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

