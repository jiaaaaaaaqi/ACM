/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 21 Sep 2019 05:13:04 PM CST
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

int n, m, k;
int cas, tol, T;

struct Node {
	int x, y;
	char id;
	bool operator < (Node a) const {
		return x<a.x;
	}
} edge[maxn];
vector<int> vv;

int getid(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin()+1;
}

ll node[maxn<<2], lazy[maxn<<2];

void build(int l, int r, int rt) {
	node[rt] = lazy[rt] = 0;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void pushup(int rt) {
	node[rt] = node[rt<<1] + node[rt<<1|1];
}

void pushdown(int rt, int lnum, int rnum) {
	if(lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		node[rt<<1] += lazy[rt]*lnum;
		node[rt<<1|1] += lazy[rt]*rnum;
		lazy[rt] = 0;
	}
}

void update(int l, int r, int pl, int pr, int rt) {
	if(pl <= l && r <= pr) {
		node[rt] += r-l+1;
		lazy[rt]++;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(pl<=mid)	update(l, mid, pl, pr, rt<<1);
	if(pr>mid)	update(mid+1, r, pl, pr, rt<<1|1);
	pushup(rt);
}

ll query(int l, int r, int p, int rt) {
	if(l == r)	return node[rt];
	int mid = l+r>>1;
	pushdown(rt, mid-l+1, r-mid);
	if(p <= mid)	return query(l, mid, p, rt<<1);
	else	return query(mid+1, r, p, rt<<1|1);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		vv.clear();
		vv.pb(0), vv.pb(m);
		for(int i=1; i<=k; i++) {
			char s[5];
			scanf("%d%d%s", &edge[i].x, &edge[i].y, s+1);
			edge[i].id = s[1];
			vv.pb(edge[i].y);
		}
		sort(edge+1, edge+1+k);
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		tol = vv.size();
		for(int i=1; i<=k; i++) {
			edge[i].y = getid(edge[i].y);
		}
		ll ans = 0;
		build(1, tol, 1);
		for(int i=1; i<=k; i++) {
			int d = edge[i].y;
			if(edge[i].id == 'R')	continue;
			if(edge[i].id == 'L') {
				ans += query(1, tol, d, 1);
			}
			if(edge[i].id == 'U') {
				update(1, tol, d, tol, 1);
			}
			if(edge[i].id == 'D') {
				update(1, tol, 1, d, 1);
			}
		}
		build(1, tol, 1);
		for(int i=k; i>=1; i--) {
			int d = edge[i].y;
			if(edge[i].id == 'L')	continue;
			if(edge[i].id == 'R') {
				ans += query(1, tol, d, 1);
			}
			if(edge[i].id == 'U') {
				update(1, tol, d, tol, 1);
			}
			if(edge[i].id == 'D') {
				update(1, tol, 1, d, 1);
			}
		}
		printf("%lld\n", ans+1);
	}
	return 0;
}

