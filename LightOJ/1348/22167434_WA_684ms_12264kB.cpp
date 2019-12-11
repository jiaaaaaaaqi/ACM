/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 11 Oct 2019 12:08:34 AM CST
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

int a[maxn];

int tot;
vector<int> vv[maxn];
int sz[maxn], fa[maxn], deep[maxn], son[maxn];
int top[maxn], id[maxn], rk[maxn];

void init() {
	tot = 0;
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
		if(sz[v] > sz[son[u]])
			son[u] = v;
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
	node[rt] = node[rt<<1]+node[rt<<1|1];
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
	if(p<=mid)	update(l, mid, p, w, rt<<1);
	else	update(mid+1, r, p, w, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt];
	}
	int mid = l+r>>1;
	int ans = 0;
	if(pl<=mid)	ans += query(l, mid, pl, pr, rt<<1);
	if(pr>mid)	ans += query(mid+1, r, pl, pr, rt<<1|1);
	return ans;
}

void upd(int u, int w) {
	update(1, n, id[u], w, 1);
}

int qry(int x, int y) {
	int ans = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]])	swap(x, y);
		ans += query(1, n, id[top[x]], id[x], 1);
		x = fa[top[x]];
	}
	if(deep[x] > deep[y])	swap(x, y);
	ans += query(1, n, id[x], id[y], 1);
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		for(int i=1, u, v; i<n; i++) {
			scanf("%d%d", &u, &v);
			u++, v++;
			vv[u].pb(v);
			vv[v].pb(u);
		}
		dfs1(1, 0);
		dfs2(1, 1);
		build(1, n, 1);
		int q;
		scanf("%d", &q);
		while(q--) {
			int id;
			scanf("%d", &id);
			if(id == 0) {
				int u, v;
				scanf("%d%d", &u, &v);
				printf("%d\n", qry(u+1, v+1));
			} else {
				int u, w;
				scanf("%d%d", &u, &w);
				upd(u+1, w);
			}
		}
	}
	return 0;
}

