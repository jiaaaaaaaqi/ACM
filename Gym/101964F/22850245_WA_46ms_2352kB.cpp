/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 13 Nov 2019 02:16:00 PM CST
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

int n, m;
int cas, tol, T;

struct E {
	int l, r, w;
} e[maxn];
int a[maxn], b[maxn], c[maxn];
vector<E> vv;

void solve(int l, int r, int p) {
	int Min, Max;
	Min = Max = a[l];
	for(int i=l; i<=r; i++)	Min = min(Min, a[i]), Max = max(Max, a[i]);
	if(Min == Max && Min == c[p])	return ;
	if(Min == c[p]) {
		vv.pb(E{l, r, 0});
	} else if(Max == c[p]) {
		vv.pb(E{l, r, 1});
	} else {
		if(l < p) {
			Min = Max = a[l];
			for(int i=l; i<=p; i++)	Min = min(Min, a[i]), Max = max(Max, a[i]);
			if(Min == c[p]) {
				vv.pb({l, p, 0});
			} else if(Max == c[p]) {
				vv.pb({l, p, 1});
			} else {
				if(a[p-1] > a[p]) {
					if(l != p-1) vv.pb({l, p-1, 1});
					vv.pb({l, p, 0});
				} else {
					if(l != p-1) vv.pb({l, p-1, 0});
					vv.pb({l, p, 1});
				}
			}
		}
		if(p < r) {
			Min = Max = a[r];
			for(int i=r; i>=p; i--)	Min = min(Min, a[i]), Max = max(Max, a[i]);
			if(Min == c[p]) {
				vv.pb({p, r, 0});
			} else if(Max == c[p]) {
				vv.pb({p, r, 1});
			} else {
				if(a[p+1] > a[p]) {
					if(p+1 != r) vv.pb({p+1, r, 1});
					vv.pb({p, r, 0});
				} else {
					if(p+1 != r) vv.pb({p+1, r, 0});
					vv.pb({p, r, 1});
				}
			}
		}
	}
	for(int i=l; i<=r; i++)	a[i] = c[p];
}

bool check() {
	for(int i=1; i<=n; i++)	if(a[i]!=b[i])	return 0;
	return 1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d", &c[i]), a[i] = c[i];
	for(int i=1; i<=n; i++)	scanf("%d", &b[i]);
	int L = 1; tol = 0;
	for(int i=1, j=1; i<=n; i=j) {
		while(L<=n && c[L] != b[i])	L++;
		if(L == n+1)	return 0*puts("-1");
		while(j<=n && b[j] == b[i])	j++;
		e[++tol] = E{i, max(j-1, L), L};
	}
	// for(int i=1; i<=tol; i++)	printf("%d %d %d\n", e[i].l, e[i].r, e[i].w);
	vv.clear();	
	for(int i=1; i<=tol; i++)	solve(e[i].l, e[i].r, e[i].w);
	for(int i=tol; i>=1; i--)	solve(e[i].l, e[i].r, e[i].w);
	printf("%d\n", (int)vv.size());
	for(auto v : vv)	printf("%c %d %d\n", v.w?'M':'m', v.l, v.r);
	return 0;
}

