/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月07日 星期四 23时15分55秒
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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e4 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
int dp[maxn][maxn];

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(dp, inf);
		mes(s, 0);
		scanf("%s", s+1);
		n = strlen(s+1);
		for(int i=1; i<=n; i++) {
			dp[i][i] = 1;
			dp[i][i-1] = 0;
			dp[i+1][i] = 0;
		}
		for(int d=2; d<=n; d++) {
			for(int i=1, j=d; j<=n; i++, j++) {
				dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
				if(s[i] == s[j])
					dp[i][j] += 1+dp[i+1][j-1];
				dp[i][j] = (dp[i][j]%mod + mod) % mod;
			}
		}
		printf("Case %d: %d\n", cas++, dp[1][n]);
	}
	return 0;
}
