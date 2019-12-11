/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月07日 星期四 00时25分48秒
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
const int    maxn = 2e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], b[maxn];
ll dp[maxn][maxn];

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(dp, inf);
		mes(a, 0), mes(b, 0);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int i=1; i<=n; i++)	scanf("%d", &b[i]);
		for(int i=1; i<=n; i++) {
			dp[i][i] = a[i] + b[i-1] + b[i+1];
			dp[i][i-1] = 0;
		}
		dp[n+1][n] = 0;
		for(int d=2; d<=n; d++) {
			for(int i=1, j=d; j<=n; i++, j++) {
				for(int k=i; k<=j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j] + a[k]+b[i-1]+b[j+1]);
				}
				// printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
			}
		}
		printf("Case #%d: %lld\n", cas++, dp[1][n]);
	}
	return 0;
}
