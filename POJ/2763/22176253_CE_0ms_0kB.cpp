/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 11 Oct 2019 05:08:31 PM CST
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
	int u, v, w;
} edge[maxn];

int tot;
int a[maxn];
vector<int> vv[maxn];
int fa[maxn], sz[maxn], son[maxn], deep[maxn];
int top[maxn], id[maxn], rk[maxn];

void init() {
	tot = deep[0] = 0;
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

void dfs1(int u, int f) {
	fa[u] = f;
	sz[u] = 1;
	son[u] = 0;
	deep[u] = deep[f]+1;
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == f)	continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]])	son[u] = v;
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	id[u] = ++tot;
	rk[tot] = u;
	if(son[u] == 0)	return ;
	dfs2(son[u], tp);
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == fa[u] || v == son[u])	continue;
		dfs2(v, v);
	}
}

int node[maxn<<2];

void pushup(int rt) {
	node[rt] = node[rt<<1]+node[rt<<1|1];
}

void build(int l, int r, int rt) {
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
	if(p>mid)	update(mid+1, r, p, w, rt<<1|1);
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

void upd(int x, int w) {
	update(1, n, id[x], w, 1);
}

int qry(int x, int y) {
	int ans = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]]) swap(x, y);
		ans += query(1, n, id[top[x]], id[x], 1);
		x = fa[top[x]];
	}
	if(x != y) {
		if(deep[x] > deep[y])	swap(x, y);
		ans += query(1, n, id[x]+1, id[y], 1);
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	int s;
	scanf("%d%d%d", &n, &m, &s);
	for(int i=1, u, v, w; i<n; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		vv[edge[i].u].pb(edge[i].v);
		vv[edge[i].v].pb(edge[i].u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	a[0] = -inf;
	for(int i=1; i<n; i++) {
		if(deep[edge[i].u] > deep[edge[i].v])	swap(edge[i].u, edge[i].v);
		a[edge[i].v] = edge[i].w;
	}
	build(1, n, 1);
	while(m--) {
		int id;
		scanf("%d", &id);
		if(id == 1) {
			int x, w;
			scanf("%d%d", &x, &w);
			upd(edge[x].v, w);
		} else {
			int v;
			scanf("%d", &v);
			printf("%d\n", qry(s, v));
			s = v;
		}
	}
	return 0;
}

