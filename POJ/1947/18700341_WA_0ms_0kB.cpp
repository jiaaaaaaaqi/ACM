/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月13日 星期三 23时33分06秒
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

vector<int> vv[maxn];
int sz[maxn], dp[maxn][maxn], a[maxn];

void dfs(int u, int f) {
	dp[u][1] = 0;
	sz[u] = 1;
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == f)	continue;
		dfs(v, u);
		sz[u] += sz[v];
		for(int j=min(sz[u], m); j>=1; j--) {
			a[j] = dp[u][j];
			dp[u][j] = inf;
		}
		for(int j=min(sz[u], m); j>=1; j--) {
			for(int k=1; k<=sz[v]; k++) {
				// if(v == 3) {
				//     printf("!!%d %d\n", u, k);
				//     printf("!!!dp[%d][%d] = %d\n", u, j, dp[u][j]);
				// }
				dp[u][j] = min(dp[u][j], dp[v][k]+a[j-k]);
				// if(v == 3) {
				//     printf("!!!dp[%d][%d] = %d\n", u, j, dp[u][j]);
				//     printf("!!!dp[%d][%d] = %d\n", v, k, dp[v][k]);
				//     printf("!!!dp[%d][%d] = %d\n", u, j-k, dp[u][j-k]);
				// }
			}
		}
		dp[u][1] = a[1]+1;
		// printf("%d %d\n", u, v);
		// for(int i=1; i<=m; i++) {
		//     printf("dp[1][%d] = %d\n", i, dp[1][i]);
		// }
	}
}

int main() {
	scanf("%d%d", &n, &m);
	mes(sz, 0), mes(dp, inf);
	for(int i=2, u, v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].push_back(v);
		vv[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", dp[1][m]);
	return 0;
}

