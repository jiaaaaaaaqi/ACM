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
int dp[maxn][maxn], a[maxn];
bool vis[maxn];

void dfs(int u) {
	dp[u][1] = 0;
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		dfs(v);
		for(int j=m; j>=1; j--) {
			a[j] = dp[u][j];
			dp[u][j] = inf;
		}
		a[0] = 0;
		for(int j=m; j>=1; j--) {
			for(int k=1; k<j; k++) {
				dp[u][j] = min(dp[u][j], dp[v][k]+a[j-k]);
			}
		}
		dp[u][1] = a[1]+1;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	mes(dp, inf);
	mes(vis, false);
	for(int i=2, u, v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].push_back(v);
		vis[v] = true;
	}
	int ans;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs(i);
			ans = dp[i][m];
			break;
		}
	}
	for(int i=1; i<=n; i++) {
		ans = min(ans, dp[i][m]+1);
	}
	printf("%d\n", ans);
	// for(int i=1; i<=n; i++) {
	//     for(int j=1; j<=m; j++) {
	//         printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	//     }
	// }
	return 0;
}

