/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 13 Sep 2019 10:39:19 PM CST
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
const int    maxn = 2e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int x, y;
	ll w;
	bool operator < (Node a) const {
		return x<a.x;
	}
} node[maxn];
struct Tree {
	ll lmax, rmax, amax, sum;
} tree[maxn<<2];
vector<int> vv;

void build(int l, int r, int rt) {
	tree[rt].lmax = tree[rt].rmax = tree[rt].amax = tree[rt].sum = -INF;
	if(l == r) {
		tree[rt].lmax = tree[rt].rmax = tree[rt].amax = tree[rt].sum = 0;
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void pushup(int rt) {
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
	tree[rt].lmax = max(tree[rt<<1].lmax, tree[rt<<1].sum+tree[rt<<1|1].lmax);
	tree[rt].rmax = max(tree[rt<<1|1].rmax, tree[rt<<1|1].sum+tree[rt<<1].rmax);
	tree[rt].amax = max(max(tree[rt<<1].amax, tree[rt<<1|1].amax), tree[rt<<1].rmax+tree[rt<<1|1].lmax);
}

void update(int l, int r, int p, ll w, int rt) {
	if(l == r) {
		tree[rt].sum += w;
		tree[rt].lmax += w;
		tree[rt].rmax += w;
		tree[rt].amax += w;
		return ;
	}
	int mid = l+r>>1;
	if(p <= mid)	update(l, mid, p, w, rt<<1);
	else	update(mid+1, r, p, w, rt<<1|1);
	pushup(rt);
}

ll solve(int p) {
	build(1, tol, 1);
	ll ans = 0;
	for(int i=p, j; i<=n; i=j) {
		for(j=i; j<=n&&node[i].x==node[j].x; j++) {
			update(1, tol, node[j].y, node[j].w, 1);
		}
		ans = max(ans, tree[1].amax);
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		vv.clear();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%lld", &node[i].x, &node[i].y, &node[i].w);
			vv.pb(node[i].y);
		}
		sort(node+1, node+1+n);
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		tol = vv.size();
		for(int i=1; i<=n; i++) {
			node[i].y = lower_bound(vv.begin(), vv.end(), node[i].y) - vv.begin()+1;
		}
		ll ans = 0;
		for(int i=1, j=1; i<=n; i=j) {
			ans = max(ans, solve(i));
			for(j=i; j<=n&&node[i].x==node[j].x; j++);
			break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

