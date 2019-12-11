/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月09日 星期六 17时14分56秒
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
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], s[maxn];
int dp[maxn][maxn];

void dfs(int l, int r) {
	if(dp[l][r])	return ;
	dp[l][r] = s[r] - s[l-1];
	for(int i=l+1; i<r; i++) {
		dfs(l, i);
		dfs(i, r);
		dp[l][r] = max(dp[l][r], s[r]-s[i-1]-dp[i][r]+s[i-1]-s[l-1]);
		dp[l][r] = max(dp[l][r], s[i]-s[l-1]-dp[l][i]+s[r]-s[i-1]);
	}
}

int main() {
	while(scanf("%d", &n), n) {
		mes(dp, 0), mes(a, 0), mes(s, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			s[i] = s[i-1] + a[i];
		}
		dfs(1, n);
		cout << 2*dp[1][n]-s[n] << endl;
	}
	return 0;
}

