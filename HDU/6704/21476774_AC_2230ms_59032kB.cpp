/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月24日 星期六 10时07分02秒
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

char s[maxn];
int a[maxn];
int rk[maxn];
int tp[maxn];
int sa[maxn];
int b[maxn];
int tax[maxn];
int dp[maxn][20];
int height[maxn];

void init() {
    mes(s, 0);
    mes(a, 0);
    mes(dp, 0);
    mes(rk, 0);
    mes(tp, 0);
    mes(sa, 0);
    mes(b, 0);
    mes(tax, 0);
    mes(height, 0);
}

void rsort(int n, int m) {
    for(int i=0; i<=m; i++) tax[i] = 0;
    for(int i=1; i<=n; i++) tax[rk[tp[i]]]++;
    for(int i=1; i<=m; i++) tax[i] += tax[i-1];
    for(int i=n; i>=1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
    return f[x] == f[y] && f[x+w] == f[y+w];
}

void SA(int *a, int n, int m) {
    for(int i=1; i<=n; i++) rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for(int p=1, w=1, i; p<n; w<<=1, m=p) {
        for(p=0, i=n-w+1; i<=n; i++)        tp[++p] = i;
        for(i=1; i<=n; i++) if(sa[i] > w)   tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for(i=2; i<=n; i++) rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
    }
    int j, k=0;
    for(int i=1; i<=n; height[rk[i++]] = k)
        for(k = k ? k-1 : k, j=sa[rk[i] - 1]; a[i+k] == a[j+k]; k++);
}

void RMQ_INIT() {
    for(int i=1; i<=n; i++)
        dp[i][0] = height[i];
    for(int j=1; j<=log(n)/log(2.0); j++) {
        for(int i=1; i<=n; i++) {
            if(i + (1<<j) - 1 <= n) {
                dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
            }
        }
    }
}

int RMQ_QUERY(int x, int y) {
    if(x > y)   swap(x, y);
    x++;
    int k = log(y-x+1) / log(2.0);
    return min(dp[x][k], dp[y-(1<<k)+1][k]);
}

struct Node{
	int l, r;
	int cnt;
} node[maxn * 40];
int rt[maxn];

void update(int l, int r, int &x, int y, int pos) {
	tol++;
	node[tol] = node[y];
	node[tol].cnt++;
	x = tol;
	if(l == r)	return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(l, mid, node[x].l, node[y].l, pos);
	else
		update(mid+1, r, node[x].r, node[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
	if(node[y].cnt-node[x].cnt < k)	return -1;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int cnt = node[node[y].l].cnt - node[node[x].l].cnt;
	if(k <= cnt)
		return query(l, mid, node[x].l, node[y].l, k);
	else
		return query(mid+1, r, node[x].r, node[y].r, k-cnt);
}

bool ok(int x, int y, int len) {
	if(RMQ_QUERY(x, y) >= len)	return 1;
	else	return 0;
}

int getL(int x, int len) {
	int l = 1, r = x-1;
	int ans = x;
	while(l<=r) {
		int mid = l+r>>1;
		if(ok(mid, x, len))	ans = mid, r = mid-1;
		else	l = mid+1;
	}
	return ans;
}

int getR(int x, int len) {
	int l = x+1, r = n;
	int ans = x;
	while(l<=r) {
		int mid = l+r>>1;
		if(ok(x, mid, len))	ans = mid, l = mid+1;
		else	r = mid-1;
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		tol = 0;
		mes(node, 0);
		mes(rt, 0);
		scanf("%d%d", &n, &m);
		scanf("%s", s+1);
		s[++n] = 1;
		for(int i=1; i<=n; i++)	a[i] = s[i];
		SA(a, n, 300);
		RMQ_INIT();
		for(int i=1; i<=n; i++) {
			update(1, n, rt[i], rt[i-1], sa[i]);
		}
		int l, r, k;
		while(m--) {
			scanf("%d%d%d", &l, &r, &k);
			int L = getL(rk[l], r-l+1);
			int R = getR(rk[l], r-l+1);
			ll ans = query(1, n, rt[L-1], rt[R], k);
			printf("%lld\n", ans);
		}
	}
    return 0;
}

/*
1
5 1
aaaba
3 3 5

*/
