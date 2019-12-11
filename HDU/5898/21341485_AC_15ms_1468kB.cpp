/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月16日 星期五 15时12分57秒
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

int digit[22];
ll dp[22][22][22];
//odd 奇数 
//even 偶数
ll dfs(int pos, int odd, int even, bool lead, bool limit) {
	if(pos == 0) {
		if(lead)	return 0;
		if(odd==0 && even%2==1)	return 1;
		if(even==0 && odd%2==0)	return 1;
		return 0;
	}
	if(!limit && !lead && dp[pos][odd][even] != -1)	return dp[pos][odd][even];
	int up = limit ? digit[pos] : 9;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		if(i==0 && lead) {
			ans += dfs(pos-1, 0, 0, lead&&i==0, limit&&i==digit[pos]);
			continue;
		}
		if(i%2 == 1) {
			if(lead)
				ans += dfs(pos-1, 1, 0, lead&&i==0, limit&&i==digit[pos]);
			else if(odd==0 && even%2==1)
				ans += dfs(pos-1, 1, 0, lead&&i==0, limit&&i==digit[pos]);
			else if(even==0 && odd)
				ans += dfs(pos-1, odd+1, 0, lead&&i==0, limit&&i==digit[pos]);
		} else {
			if(lead)
				ans += dfs(pos-1, 0, 1, lead&&i==0, limit&&i==digit[pos]);
			else if(odd==0 && even)
				ans += dfs(pos-1, 0, even+1, lead&&i==0, limit&&i==digit[pos]);
			else if(even==0 && odd%2==0)
				ans += dfs(pos-1, 0, 1, lead&&i==0, limit&&i==digit[pos]);
		}
	}
	if(!limit && !lead)	dp[pos][odd][even] = ans;
	return ans;
}

ll solve(ll x) {
	int pos = 0;
	while(x) {
		digit[++pos] = x%10;
		x /= 10;
	}
	return dfs(pos, 0, 0, true, true);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	mes(dp, -1);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll ans = solve(m)-solve(n-1);
		printf("Case #%d: %lld\n", cas++, ans);
	}
    return 0;
}

