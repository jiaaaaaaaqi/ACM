/*************************************************************** 
	> File Name		: C.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 03:09:48 PM CST
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
	ll A, B;
} e[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)	e[i] = E{0, 0};
	ll all = 0;
	for(int i=1; i<=n; i++) {
		int x;ll A, B;
		scanf("%d%lld%lld", &x, &A, &B);
		all += A+B;
		e[x].A += A;
		e[x].B += B;
	}
	ll wA, wB;
	wA = wB = 0;
	for(int i=1; i<=m; i++) {
		ll tA = e[i].A, tB = e[i].B;
		if(e[i].A > e[i].B)	tA = max(0ll, e[i].A - ((e[i].A+e[i].B)/2+1));
		if(e[i].A < e[i].B)	tB = max(0ll, e[i].B - ((e[i].A+e[i].B)/2+1));
		wA += tA, wB += tB;
		if(e[i].A > e[i].B)	printf("A %lld %lld\n", tA, tB);
		if(e[i].A < e[i].B)	printf("B %lld %lld\n", tA, tB);
	}
	double ans = 1.0*abs(wA-wB) / all;
	printf("%.10f\n", ans);
	return 0;
}

