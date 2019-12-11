/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月01日 星期五 18时11分01秒
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

int tot, a[maxn];
int fa[maxn], sz[maxn], deep[maxn], son[maxn];
int top[maxn], id[maxn], rk[maxn];
vector<int> vv[maxn];

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
		if(v==fa[u] || v==son[u])	continue;
		dfs2(v, v);
	}
}

struct Node {
	int lazy, all;
	int lsum, rsum, asum;
	Node() {
		all = lsum = rsum = asum = 0;
	}
} node[maxn<<2];

Node bind(Node x, Node y) {
	Node ans;
	ans.all = x.all + y.all;
	ans.lsum = max(x.lsum, x.all+y.lsum);
	ans.rsum = max(y.rsum, y.all+x.rsum);
	ans.asum = max(max(x.asum, y.asum), x.rsum+y.lsum);
	return ans;
}

void pushup(int rt) {
	int x = node[rt].lazy;
	node[rt] = bind(node[rt<<1], node[rt<<1|1]);
	node[rt].lazy = x;
}

void pushdown(int rt, int lnum, int rnum) {
	if(node[rt].lazy != inf) {
		node[rt<<1].lazy = node[rt<<1|1].lazy = node[rt].lazy;
		node[rt<<1].all = node[rt].lazy * lnum;
		node[rt<<1|1].all = node[rt].lazy * rnum;
		node[rt<<1].lsum = node[rt<<1].rsum = node[rt<<1].asum = max(0, node[rt].lazy*lnum);
		node[rt<<1|1].lsum = node[rt<<1|1].rsum = node[rt<<1|1].asum = max(0, node[rt].lazy*rnum);
		node[rt].lazy = inf;
	}
}

void build(int l, int r, int rt) {
	node[rt].lazy = inf;
	node[rt].all = node[rt].lsum = node[rt].rsum = node[rt].asum = 0;
	if(l == r) {
		node[rt].all = a[rk[l]];
		node[rt].lsum = node[rt].rsum = node[rt].asum = max(0, a[rk[l]]);
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int pl, int pr, int w, int rt) {
	if(pl<=l && r<=pr) {
		node[rt].lazy = w;
		node[rt].all = w*(r-l+1);
		node[rt].lsum = node[rt].rsum = node[rt].asum = max(0, w*(r-l+1));
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(pl<=mid)	update(l, mid, pl, pr, w, rt<<1);
	if(pr>mid)	update(mid+1, r, pl, pr, w, rt<<1|1);
	pushup(rt);
}

Node query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt];
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	Node ans, res;
	if(pl<=mid)	ans = bind(ans, query(l, mid, pl, pr, rt<<1));
	if(pr>mid)	ans = bind(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

Node QRY(int x, int y) {
	Node ans1, ans2;
	while(top[x] != top[y]) {
		if(deep[top[x]] > deep[top[y]]) {
			Node res = query(1, n, id[top[x]], id[x], 1);
			ans1 = bind(res, ans1);
			x = fa[top[x]];
		} else {
			Node res = query(1, n, id[top[y]], id[y], 1);
			ans2 = bind(res, ans2);
			y = fa[top[y]];
		}
	}
	if(deep[x] > deep[y]) {
		Node res = query(1, n, id[y], id[x], 1);
		ans1 = bind(res, ans1);
	} else {
		Node res = query(1, n, id[x], id[y], 1);
		ans2 = bind(res, ans2);
	}
	swap(ans1.lsum, ans1.rsum);
	Node ans = bind(ans1, ans2);
	return ans;
}

void UPD(int x, int y, int w) {
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]])	swap(x, y);
		update(1, n, id[top[x]], id[x], w, 1);
		x = fa[top[x]];
	}
	if(deep[x] > deep[y])	swap(x, y);
	update(1, n, id[x], id[y], w, 1);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	init();
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1, u, v; i<n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].pb(v), vv[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	scanf("%d", &m);
	build(1, n, 1);
	int id, x, y, w;
	while(m--) {
		scanf("%d", &id);
		if(id == 1) {
			scanf("%d%d", &x, &y);
			Node ans = QRY(x, y);
			printf("%d\n", ans.asum);
		} else {
			scanf("%d%d%d", &x, &y, &w);
			UPD(x, y, w);
		}
	}
    return 0;
}

