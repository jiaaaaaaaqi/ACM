/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 04 Sep 2019 10:41:10 PM CST
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

struct Node {
	int l, r;
	int cnt;
} node[maxn*40];
int a[maxn], rt[maxn];
vector<int> vv;

void init() {
	tol = 0;
	vv.clear();
	mes(rt, 0);
	mes(node, 0);
}

int getid1(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin()+1;
}

int getid2(int x) {
	return upper_bound(vv.begin(), vv.end(), x) - vv.begin();
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

int query(int l, int r, int x, int y, int k) {
	if(k == 0)	return 0;
	if(l == r)	return node[y].cnt-node[x].cnt;
	int ans = node[node[y].l].cnt - node[node[x].l].cnt;
	int mid = l+r>>1;
	if(k<=mid)	return query(l, mid, node[x].l, node[y].l, k);
	else	return ans+query(mid+1, r, node[x].r, node[y].r, k);
}

int calc(int L, int R, int p, int k) {
	int l=0, r=1000000, ans;
	while(l<=r) {
		int mid = l+r>>1;
		int id1 = getid2(p+mid), id2 = getid1(p-mid)-1;
		int cnt = query(1, n, rt[L], rt[R], id1) - query(1, n, rt[L], rt[R], id2);
		if(cnt >= k)	ans = mid, r = mid-1;
		else l = mid+1;
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]), vv.pb(a[i]);
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		for(int i=1; i<=n; i++) {
			a[i] = getid1(a[i]);
			update(1, n, rt[i], rt[i-1], a[i]);
		}
		int ans = 0;
		int l, r, p, k;
		while(m--) {
			scanf("%d%d%d%d", &l, &r, &p, &k);
			l^=ans, r^=ans, p^=ans, k^=ans;
			ans = calc(l-1, r, p, k);
			printf("%d\n", ans);
		}
	}
	return 0;
}

