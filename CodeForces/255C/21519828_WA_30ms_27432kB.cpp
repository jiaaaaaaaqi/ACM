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
int dp[2][1000005][2];
vector<int> vv[1000005];

int solve(int x, vector<int> vv, int len) {
	if(vv.size() == 0)	return 0;
	int f = 0;
	for(int i=0; i<=len; i++)
		dp[0][i][0] = dp[1][i][0] = dp[0][i][1] = dp[1][i][1] = 1;
	int sz = vv.size();
	int ans = sz, id;
	for(int i=1; i<sz; i++) {
		f = !f;
		for(int j=1; j<=len; j++)	
			dp[f][j][0] = dp[f][j][1] = 1;
		int now = vv[i];
		for(int last=vv[i-1]+1; last<=now-1; last++) {
			if(a[last] < x)	id = 1;
			else	id = 0;
			int tmp = abs(a[last]-x);
			dp[f][tmp][id] = max(dp[f][tmp][id], dp[!f][tmp][id]+2);
			ans = max(ans, dp[f][tmp][id]);
		}
	}
	f = !f;
	for(int last=vv[sz-1]+1; last<=n; last++) {
		if(a[last] < x)	id = 1;
		else	id = 0;
		int tmp = abs(a[last]-x);
		dp[f][tmp][id] = max(dp[f][tmp][id], dp[!f][tmp][id]+1);
		ans = max(ans, dp[f][tmp][id]);
	}
	return ans;
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
		ans = max(ans, solve(i, vv[i], mx-i));
	}
	printf("%d\n", ans);
    return 0;
}

