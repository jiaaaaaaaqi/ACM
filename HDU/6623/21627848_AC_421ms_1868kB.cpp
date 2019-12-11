/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 04 Sep 2019 04:43:29 PM CST
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

ll n, m;
int cas, tol, T;

int pri[maxn];
bool ispri[maxn];

void handle() {
	tol = 0;
	mes(pri, 0), mes(ispri, 1);
	int mx = 5000;
	for(int i=2; i<=mx; i++) {
		if(ispri[i])	pri[++tol] = i;
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0)	break;
		}
	}
}

int ans;
ll solve1(ll x) {
	for(int i=1; i<=tol&&pri[i]<=x; i++) {
		if(x%pri[i] == 0) {
			int cnt = 0;
			while(x%pri[i] == 0) {
				x /= pri[i];
				cnt++;
			}
			ans = min(ans, cnt);
		}
	}
	return x;
}

bool calc(ll x, int c) {
	ll l = 1, r;
	if(c == 2)	r = 1e9;
	else if(c == 3)	r = 1e6;
	else r = 31622;
	while(l<=r) {
		ll mid = l+r>>1;
		ll tmp = 1ll;
		for(int i=1; i<=c; i++)	tmp = tmp*mid;
		if(tmp == x)	return 1;
		if(tmp < x)	l = mid+1;
		else	r = mid-1;
	}
	return 0;
}

int solve2(ll x) {
	if(calc(x, 4))	return 4;
	else if(calc(x, 3))	return 3;
	else if(calc(x, 2))	return 2;
	else return 1;
}

int main() {
	// freopen("in", "r", stdin);
	handle();	
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		ans = inf;
		n = solve1(n);
		if(n != 1)	ans = min(ans, solve2(n));
		printf("%d\n", ans);
	}
	return 0;
}

