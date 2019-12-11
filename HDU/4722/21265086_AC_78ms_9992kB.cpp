/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月13日 星期二 10时35分08秒
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

ll dp[maxn][11];
int digit[maxn];

ll dfs(int pos, int sum, bool lead, bool limit) {
	if(pos == 0) {
		if(sum==0 && lead==0)	return 1;
		else	return 0;
	}
	if(!lead && !limit && dp[pos][sum] != -1)	return dp[pos][sum];
	int up = limit ? digit[pos] : 9;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		ans += dfs(pos-1, (sum+i)%10, lead&&i==0, limit&&i==digit[pos]);
	}
	if(!lead && !limit)	dp[pos][sum] = ans;
	return ans;
}

ll solve(ll x) {
	if(x == -1)	return 0;
	int pos = 0;
	while(x) {
		digit[++pos] = x%10;
		x /= 10;
	}
	return dfs(pos, 0, 1, 1);
}

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	mes(dp, -1);
	while(T--) {
		scanf("%I64d%I64d", &n, &m);
		ll ans = solve(m) - solve(n-1);
		if(n == 0)	ans++;
		printf("Case #%d: %I64d\n", cas++, ans);
	}
    return 0;
}

