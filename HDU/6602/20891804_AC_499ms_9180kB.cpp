/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 29 Jul 2019 11:06:40 PM CST
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
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
int C, K;
int cas, tol, T;

int cnt[maxn];
int a[maxn], p[maxn];
vector<int> vv[maxn];
struct Node {
	int mi;
	int lazy;
} node[maxn<<2];

void handle() {
	for(int i=1; i<=n; i++) {
		p[i] = ++cnt[a[i]];
		vv[a[i]].push_back(i);
	}
}

void pushup(int rt) {
	node[rt].mi = min(node[rt<<1].mi, node[rt<<1|1].mi);
}

void pushdown(int rt) {
	if(node[rt].lazy) {
		node[rt<<1].mi += node[rt].lazy;
		node[rt<<1|1].mi += node[rt].lazy;
		node[rt<<1].lazy += node[rt].lazy;
		node[rt<<1|1].lazy += node[rt].lazy;
		node[rt].lazy = 0;
	}
}

void build(int l, int r, int rt) {
	node[rt].mi = 0;
	node[rt].lazy = 0;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, int val, int rt) {
	if(pl<=l && r<=pr) {
		node[rt].mi += val;
		node[rt].lazy += val;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt);	
	if(pl<=mid)	update(l, mid, pl, pr, val, rt<<1);
	if(pr>mid)	update(mid+1, r, pl, pr, val, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(l == r) {
		if(node[rt].mi == 0)	return l;
		else	return inf;
	}
	if(pl<=l && r<=pr) {
		int mid = l+r>>1;
		pushdown(rt);
		if(node[rt<<1].mi == 0)	return query(l, mid, pl, pr, rt<<1);
		else if(node[rt<<1|1].mi == 0)	return query(mid+1, r, pl, pr, rt<<1|1);
		else	return inf;
	}
	int mid = l+r>>1;
	pushdown(rt);
	if(pl <= mid) {
		int ans = query(l, mid, pl, pr, rt<<1);
		if(ans != inf)	return ans;
	}
	if(pr > mid) {
		int ans = query(mid+1, r, pl, pr, rt<<1|1);
		if(ans != inf)	return ans;
	}
	return inf;
}

int querymin(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt].mi;
	}
	int mid = l+r>>1;
	pushdown(rt);
	int ans = inf;
	if(pl <= mid)
		ans = min(ans, querymin(l, mid, pl, pr, rt<<1));
	if(pr > mid)
		ans = min(ans, querymin(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

void del(int x, int p) {
	int l = p-K;
	int r = p-1;
	int left, right;
	if(l<=0)	left = 1;
	else	left = vv[a[x]][l-1]+1;
	if(r==0)	return ;
	right = vv[a[x]][r-1];
	update(1, n, left, right, -1, 1);
	// printf("del %d %d\n", left, right);
	// printf("querymin %d - %d = %d\n", left, right, querymin(1, n, 1, 1, 1));
}

void add(int x, int p) {
	int l = p-K+1;
	int r = p;
	int left, right;
	if(l<=0)	left = 1;
	else	left = vv[a[x]][l-1]+1;
	right = vv[a[x]][r-1];
	update(1, n, left, right, 1, 1);
	// printf("add %d %d\n", left, right);
	// printf("querymin %d - %d = %d\n", left, right, querymin(1, n, 1, 1, 1));
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d%d", &n, &C, &K)) {
		for(int i=1; i<=C; i++) {
			vv[i].clear();
			cnt[i] = 0;
		}
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			p[i] = 0;
		}
		handle();
		build(1, n, 1);
		int ans = 0;
		for(int i=1; i<=n; i++) {
			del(i, p[i]);
			add(i, p[i]);
			ans = max(ans, i-query(1, n, 1, i, 1)+1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

