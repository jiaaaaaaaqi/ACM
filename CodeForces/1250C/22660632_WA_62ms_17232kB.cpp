/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月03日 星期日 16时01分50秒
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll k;
struct Ask {
	int l, r, id;
	ll p;
} ask[maxn];

bool cmp1(Ask a, Ask b) {
	return a.r<b.r;
}

bool cmp2(Ask a, Ask b) {
	return a.l<b.l;
}

ll node[maxn<<2], lazy[maxn<<2];

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		node[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		node[rt<<1|1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void pushup(int rt) {
	node[rt] = max(node[rt<<1], node[rt<<1|1]);
}

void build(int l, int r, int rt) {
	node[rt] = lazy[rt] = 0;
	if(l == r) return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, ll val, int rt) {
	if(pl<=l && r<=pr) {
		lazy[rt] += val;
		node[rt] += val;
		return ;
	}
	int mid = l+r>>1;
	pushdown(mid);
	if(pl<=mid)	update(l, mid, pl, pr, val, rt<<1);
	if(pr>mid)	update(mid+1, r, pl, pr, val, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, ll ans, int rt) {
	if(l == r)	return l;
	int mid = l+r>>1;
	pushdown(rt);
	if(node[rt<<1] == ans)	return query(l, mid, ans, rt<<1);
	else	return query(mid+1, r, ans, rt<<1|1);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%lld", &n, &k);
	int maxtime = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d%d%lld", &ask[i].l, &ask[i].r, &ask[i].p);
		ask[i].id = i;
		maxtime = max(maxtime, ask[i].r);
	}
	sort(ask+1, ask+1+n, cmp1);
	build(1, maxtime, 1);
	{
		int p = 1;
		ll val = 0;
		for(int i=1; i<=maxtime; i++) {
			while(p<=n && ask[p].r==i) {
				val += ask[p].p;
				p++;
			}
			val -= k;
			update(1, maxtime, i, i, val, 1);
		}
	}
	sort(ask+1, ask+1+n, cmp2);
	ll ans = 0;
	pair<int, int> pa;
	{
		int p = 1;
		for(int i=1; i<=maxtime; i++) {
			ll val = 0;
			if(ans < node[1]) {
				ans = node[1];
				int pos = query(1, maxtime, ans, 1);
				pa = pair<int, int>(i, pos);
			}
			while(p<=n && ask[p].l==i) {
				val += ask[p].p;
				p++;
			}
			val -= k;
			if(i != maxtime)
				update(1, maxtime, i+1, maxtime, -val, 1);
			update(1, maxtime, i, i, -INF, 1);
		}
	}
	if(ans == 0) {
		printf("0\n");
	} else {
		vector<int> vv;
		vv.clear();
		for(int i=1; i<=n; i++) {
			if(pa.fi <= ask[i].l && ask[i].r <= pa.se)	vv.pb(ask[i].id);
		}
		printf("%lld %d %d %d\n", ans, pa.fi, pa.se, vv.size());
		for(int i=0; i<vv.size(); i++)	printf("%d%c", vv[i], i==vv.size()-1?'\n':' ');
	}
    return 0;
}

