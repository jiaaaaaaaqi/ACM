/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 12:54:48 PM CST
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
const int    maxn = 4e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int node[maxn<<2];
int a[maxn], pr[maxn], p[maxn];

void build(int l, int r, int rt) {
	node[rt] = inf;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	node[rt] = min(node[rt<<1], node[rt<<1|1]);
}

void update(int l, int r, int p, int v, int rt) {
	if(l == r) {
		node[rt] = v;
		return ;
	}
	int mid = l+r>>1;
	if(p <= mid)	update(l, mid, p, v, rt<<1);
	else	update(mid+1, r, p, v, rt<<1|1);
	node[rt] = min(node[rt<<1], node[rt<<1|1]);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr)	return node[rt];
	int mid = l+r>>1, ans = inf;
	if(pl<=mid)	ans = min(ans, query(l, mid, pl, pr, rt<<1));
	if(pr>mid)	ans = min(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]), p[a[i]] = -1;
	for(int i=n; i>=1; i--) {
		pr[i] = p[a[i]];
		p[a[i]] = i;
	}
	build(1, n, 1);
	pair<int, int> ans;
	ans.fi = ans.se = inf;
	for(int i=1; i<=n; i++) {
		int l = i+1, r = pr[i]-1;
		if(l<=r) {
			int t = query(1, n, l, r, 1);
			ans = min(ans, pair<int, int>{t, a[i]});
		}
		if(pr[i] != -1)	update(1, n, pr[i], a[i], 1);
	}
	if(ans.fi == inf || ans.se == inf)	printf("-1\n");
	else	printf("%d %d\n", ans.fi, ans.se);
	return 0;
}

