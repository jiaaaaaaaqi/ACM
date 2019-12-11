/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月13日 星期六 15时13分03秒
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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int x[maxn], y[maxn];
bool vis[maxn][maxn];
double dis[maxn][maxn], dp[maxn][maxn];

void dfs(int i, int j) {
	if(i==j && i!=1)	return ;
	if(dp[i][j] == DBL_MAX)	return ;
	if(vis[i][j])	return ;
	if(i==n)	return;
	vis[i][j] = true;
	dp[i+1][j] = min(dp[i+1][j], dp[i][j]+dis[i][i+1]);
	dfs(i+1, j);
	dp[i+1][i] = min(dp[i+1][i], dp[i][j]+dis[j][i+1]);
	dfs(i+1, i);
}

int main() {
	while(~scanf("%d", &n)) {
		mes(vis, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			for(int j=1; j<=i; j++) {
				dis[i][j] = dis[j][i] = hypot(x[i]-x[j], y[i]-y[j]);
				dp[i][j] = dp[j][i] = DBL_MAX;
			}
		}
		dp[1][1] = 0;
		dfs(1, 1);
		// for(int i=1; i<=n; i++) {
		//     for(int j=1; j<=n; j++) {
		//         printf("%f%c", dp[i][j], j==n ? '\n' : ' ');
		//     }
		// }
		double ans = DBL_MAX;
		for(int i=1; i<=n; i++) {
			ans = min(ans, dp[n][i]+dis[i][n]);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

