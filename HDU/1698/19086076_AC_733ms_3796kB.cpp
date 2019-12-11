/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019/4/4 18:21:23
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
int cas, tol, T;

struct Node{
	int val;
	int lazy;
}node[maxn<<2];

void pushdown(int rt, int l, int r) {
	if(node[rt].lazy != -1) {
		node[rt<<1].lazy = node[rt<<1|1].lazy = node[rt].lazy;
		node[rt<<1].val = l*node[rt].lazy;
		node[rt<<1|1].val = r*node[rt].lazy;
		node[rt].lazy = -1;
	}
}

void pushup(int rt) {
	node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
}

void build(int l, int r, int rt) {
	node[rt].val = 0;
	node[rt].lazy = -1;
	if(l == r) {
		node[rt].val = 1;
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
		node[rt].val = (r-l+1)*w;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(pl <= mid)	update(l, mid, pl, pr, w, rt<<1);
	if(pr > mid)	update(mid+1, r, pl, pr, w, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt].val;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, rt-mid);
	int ans = 0;
	if(pl<=mid)	ans += query(l, mid, pl, pr, rt<<1);
	if(pr>mid)	ans += query(mid+1, r, pl, pr, rt<<1|1);
	return ans;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		build(1, n, 1);
		scanf("%d", &m);
		while(m--) {
			int l, r, w;
			scanf("%d%d%d", &l, &r, &w);
			update(1, n, l, r, w, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", cas++, query(1, n, 1, n, 1));
	}
	return 0;
}

