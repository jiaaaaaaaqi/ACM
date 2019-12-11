/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月29日 星期一 10时44分56秒
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

ll a[maxn];
vector<ll> vv;
struct Node {
	int l, r;
	int cnt;	
} node[maxn*40];
int rt[maxn];

ll getid(ll x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void init() {
	tol = 0;
	vv.clear();
	mes(node, 0);
	mes(rt, 0);
}

void update(int l, int r, int &x, int y, int pos) {
	tol++;
	node[tol] = node[y];
	node[tol].cnt++;
	x = tol;
	if(l == r)	return ;
	int mid = l+r>>1;
	if(pos <= mid)	update(l, mid, node[x].l, node[y].l, pos);
	else	update(mid+1, r, node[x].r, node[y].r, pos);
}

ll query(int l, int r, int x, int y, int k) {
	if(l == r)	return l;
	int mid = l+r>>1;
	int cnt = node[node[y].r].cnt - node[node[x].r].cnt;
	if(cnt >= k)	return query(mid+1, r, node[x].r, node[y].r, k);
	else	return query(l, mid, node[x].l, node[y].l, k-cnt);
}

ll b[5];

bool ok() {
	ll x = min({ b[0], b[1], b[2] });
	ll z = max({ b[0], b[1], b[2] });
	ll y = b[0]+b[1]+b[2]-x-z;
	if(x+y > z)	return true;
	return false;
}

ll solve(int l, int r) {
	int len = r-l+1;
	if(len <= 2)	return -1;
	b[1] = vv[query(1, n, rt[l-1], rt[r], 1)-1];
	b[2] = vv[query(1, n, rt[l-1], rt[r], 2)-1];
	for(int i=3; i<=len; i++) {
		b[i%3] = vv[query(1, n, rt[l-1], rt[r], i)-1];
		// printf("%lld %lld %lld\n", b[0], b[1], b[2]);
		if(ok())	return b[0]+b[1]+b[2];
	}
	return -1;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
			vv.push_back(a[i]);
		}
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		for(int i=1; i<=n; i++) {
			a[i] = getid(a[i]);
			update(1, n, rt[i], rt[i-1], a[i]);
		}
		int l, r;
		while(m--) {
			scanf("%d%d", &l, &r);
			ll ans = solve(l, r);
			printf("%lld\n", ans);
		}
	}
	return 0;
}

