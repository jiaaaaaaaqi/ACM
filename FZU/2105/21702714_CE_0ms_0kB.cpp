/*************************************************************** 
  > File Name    : a.cpp
  > Author       : Jiaaaaaaaqi
  > Created Time : Wed 11 Sep 2019 03:19:42 PM CST
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
const int    maxn = 1e6 + 10;
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
struct Node {
	int a[5];
}node[maxn*4];
int lazy[maxn*4][5];

void pushup(int rt) {
	for(int i=1; i<=5; i++) {
		node[rt].a[i] = node[rt<<1].a[i] + node[rt<<1|1].a[i];
	}
}

void build(int l, int r, int rt) {
	for(int i=1; i<=5; i++)	lazy[rt][i] = 0;
	if(l == r) {
		for(int i=5; i>=1; i--) {
			node[rt].a[i] = ((a[l]&(1<<(i-1))) ? 1 : 0);
		}
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void pushdown(int rt, int lnum, int rnum) {
	for(int i=1; i<=5; i++) {
		if(lazy[rt][i] == 0)	continue;
		else {
			if(lazy[rt][i] == 1) {
				node[rt<<1].a[i] = lnum - node[rt<<1].a[i];							
				node[rt<<1|1].a[i] = rnum - node[rt<<1|1].a[i];							

				if(lazy[rt<<1][i] == 1)
					lazy[rt<<1][i] = 0;
				else if(lazy[rt<<1][i] == 2)
					lazy[rt<<1][i] = 3;
				else if(lazy[rt<<1][i] == 3)
					lazy[rt<<1][i] = 2;
				else
					lazy[rt<<1][i] = 1;

				if(lazy[rt<<1|1][i] == 1)
					lazy[rt<<1|1][i] = 0;
				else if(lazy[rt<<1|1][i] == 2)
					lazy[rt<<1|1][i] = 3;
				else if(lazy[rt<<1|1][i] == 3)
					lazy[rt<<1|1][i] = 2;
				else
					lazy[rt<<1|1][i] = 1;
			} else if(lazy[rt][i] == 2) {
				node[rt<<1].a[i] = lnum;
				node[rt<<1|1].a[i] = rnum;
				lazy[rt<<1][i] = lazy[rt<<1|1][i] = lazy[rt][i];
			} else {
				node[rt<<1].a[i] = 0;
				node[rt<<1|1].a[i] = 0;
				lazy[rt<<1][i] = lazy[rt<<1|1][i] = lazy[rt][i];
			}
		}
		lazy[rt][i] = 0;
	}
}

void update(int l, int r, int pl, int pr, int i, int id, int rt) {
	if(pl<=l && r<=pr) {
		int len = r-l+1;
		if(id == 1) {
			node[rt].a[i] = len - node[rt].a[i];
			if(lazy[rt][i] == 1)
				lazy[rt][i] = 0;
			else if(lazy[rt][i] == 2)
				lazy[rt][i] = 3;
			else if(lazy[rt][i] == 3)
				lazy[rt][i] = 2;
			else
				lazy[rt][i] = 1;
		} else if(id == 2) {
			node[rt].a[i] = len;
			lazy[rt][i] = 2;
		} else {
			node[rt].a[i] = 0;
			lazy[rt][i] = 3;
		}
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(pl <= mid)	update(l, mid, pl, pr, i, id, rt<<1);
	if(pr > mid)	update(mid+1, r, pl, pr, i, id, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int i, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt].a[i];
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	int ans = 0;
	if(pl <= mid)	ans += query(l, mid, pl, pr, i, rt<<1);
	if(pr > mid)	ans += query(mid+1, r, pl, pr, i, rt<<1|1);
	return ans;	
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		build(1, n, 1);
		int l, r, x;
		char id[6];
		while(m--) {
			scanf("%s", id);
			if(id[0] == 'S') {
				ll ans = 0;
				scanf("%d%d", &l, &r);
				l++,r++;
				for(int i=1; i<=5; i++)
					ans += 1ll*query(1, n, l, r, i, 1) * (1ll<<(i-1));
				printf("%lld\n", ans);
			} else if(id[0] == 'X') {
				scanf("%d", &x);
				scanf("%d%d", &l, &r);
				l++,r++;
				for(int i=1; i<=5; i++)
					if(x & (1<<(i-1)))
						update(1, n, l, r, i, 1, 1);
			} else if(id[0] == 'O') {
				scanf("%d", &x);
				scanf("%d%d", &l, &r);
				l++,r++;
				for(int i=1; i<=5; i++)
					if(x & (1<<(i-1)))
						update(1, n, l, r, i, 2, 1);
			} else {
				scanf("%d", &x);
				scanf("%d%d", &l, &r);
				l++,r++;
				for(int i=1; i<=5; i++)
					if(!(x&(1<<(i-1))))
						update(1, n, l, r, i, 3, 1);
			}
		}
	}
	return 0;
}
