/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 22 Sep 2019 04:48:41 PM CST
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
int a, b;
ll k;

bool ok(ll n) {
	ll lgn = log2(1.0*n);
	if((1ll<<lgn) != n)	lgn++;
	__int128 ans = 1;
	for(int i=1; i<=a; i++) {
		ans = ans*n;
		if(ans > k)	return false;
	}
	for(int i=1; i<=b; i++) {
		ans = ans*lgn;
		if(ans > k)	return false;
	}
	return ans <= k;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%lld", &a, &b, &k);
		ll l = 0, r = k;
		ll ans;
		while(l<=r) {
			ll mid = l+r>>1;
			if(ok(mid))	l = mid+1, ans=mid;
			else r = mid-1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

