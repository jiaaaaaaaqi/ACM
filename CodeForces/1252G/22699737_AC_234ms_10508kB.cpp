/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 05 Nov 2019 08:43:04 PM CST
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

int a[maxn], c[maxn];
vector<int> vv[maxn];
int node[maxn<<2], lazy[maxn<<2];

void pushdown(int rt) {
	if(lazy[rt]) {
		node[rt<<1] += lazy[rt];
		node[rt<<1|1] += lazy[rt];
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void pushup(int rt) {
	node[rt] = min(node[rt<<1], node[rt<<1|1]);
}

void build(int l, int r, int rt) {
	if(l == r) {
		node[rt] = a[l]-c[l];
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int pl, int pr, int v, int rt) {
	if(pl>pr)	return ;
	if(pl<=l && r<=pr) {
		lazy[rt] += v;
		node[rt] += v;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt);
	if(pl<=mid)	update(l, mid, pl, pr, v, rt<<1);
	if(pr>mid)	update(mid+1, r, pl, pr, v, rt<<1|1);
	pushup(rt);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	mes(a, 0);
	int x, y;
	scanf("%d", &x);
	a[1] = 1;
	for(int i=2; i<=n; i++) {
		scanf("%d", &y);
		if(x > y)	a[1]++;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d", &c[i]);
		vv[i].pb(0);
		a[i+1] = a[i];
		for(int j=1; j<=c[i]; j++) {
			scanf("%d", &y);
			if(y > x)	a[i+1]--;
			vv[i].pb(y);
		}
	}
	build(1, m, 1);
	while(k--) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		int t = vv[i][j];
		if(t<x && w>x)	update(1, m, i+1, m, -1, 1);
		if(t>x && w<x)	update(1, m, i+1, m, 1, 1);
		vv[i][j] = w;
		if(node[1] <= 0)	printf("0\n");
		else	printf("1\n");
	}
	return 0;
}

