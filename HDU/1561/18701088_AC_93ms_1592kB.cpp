/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月14日 星期四 01时15分28秒
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

void dfs(int u) {
	dp[u][0] = 0;
	dp[u][1] = a[u];
	for(auto v : vv[u]) {
		dfs(v);
		for(int j=m; j>=2; j--) {
			for(int k=0; k<j; k++) {
				dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k]);
			}
		}
	}
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		m++;
		mes(a, 0);
		for(int i=0; i<=n; i++)	vv[i].clear();
		for(int i=0; i<=n; i++)	for(int j=0; j<=m; j++)	dp[i][j] = -inf;
		for(int v=1, u, w; v<=n; v++) {
			scanf("%d%d", &u, &a[v]);
			vv[u].push_back(v);
		}
		dfs(0);
		// for(int i=0; i<=n; i++) {
		//     for(int j=0; j<=m; j++) {
		//         printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		//     }
		// }
		cout << dp[0][m] << endl;
	}
	return 0;
}

