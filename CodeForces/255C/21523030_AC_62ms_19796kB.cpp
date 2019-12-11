/*************************************************************** 
  > File Name    : a.cpp
  > Author       : Jiaaaaaaaqi
  > Created Time : 2019年08月27日 星期二 11时49分39秒
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
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int dp[2][1000005];
vector<int> vv[1000005];

int solve(vector<int> vv) {
	if(vv.size() == 0)	return 0;
	int sz = vv.size();
	int f = 0;
	for(int i=1; i<=n; i++) dp[0][a[i]] = dp[1][a[i]] = 0;;
	for(int i=1; i<sz; i++) {
		f = !f;
		int last = vv[i-1]+1;
		int now = vv[i]-1;
		for(int j=1; j<=last-2; j++) {
			dp[f][a[j]] = dp[!f][a[j]];
		}
		for(int j=last; j<=now; j++) {
			dp[f][a[j]] = dp[!f][a[j]]+1;
		}
	}
	int res = 0;
	{
		int ans = 0;
		for(int i=1; i<=vv[sz-1]; i++)
			ans = max(ans, dp[f][a[i]]);
		res = ans*2+1;
	}
	f = !f;
	int last = vv[sz-1]+1;
	int now = n;
	for(int j=1; j<=last-2; j++) {
		dp[f][a[j]] = dp[!f][a[j]];
	}
	for(int j=last; j<=now; j++) {
		dp[f][a[j]] = dp[!f][a[j]]+1;
	}
	{
		int ans = 0;
		for(int i=last; i<=n; i++)
			ans = max(ans, dp[f][a[i]]);
		res = max(res, ans*2);
	}
	return max(res, sz);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	int mn = inf, mx = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		vv[a[i]].pb(i);
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	int ans = 0;
	for(int i=mn; i<=mx; i++) {
		ans = max(ans, solve(vv[i]));
	}
	printf("%d\n", ans);
	return 0;
}
/*
5
4 4 3 5 1

*/
