/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Thu 05 Sep 2019 10:44:58 PM CST
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

void f(ll x1, ll y1, ll x2, ll y2, ll &x, ll &y) {
	ll d = x1/y1+1;
	if(x2 > d*y2) {
		x = d, y = 1;
		return ;
	}
	d--;
	f(y2, x2-d*y2, y1, x1-d*y1, y, x);
	x += d*y;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		ll p, a;
		scanf("%lld%lld", &p, &a);
		ll x, y;
		f(p, a, p, a-1, x, y);
		printf("%lld/%lld\n", x*a-y*p, x);
	}
	return 0;
}

