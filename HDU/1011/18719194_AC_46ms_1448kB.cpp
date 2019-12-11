/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月15日 星期五 01时16分12秒
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

int a[maxn], p[maxn], dp[maxn][maxn];
vector<int> vv[maxn];

void dfs(int u, int fa) {
	if(vv[u].size() == 1 && u!=1) {
		a[u] = max(a[u], 1);
	}
	for(int i=m; i>=a[u]; i--) {
		dp[u][i] = p[u];
	}
	for(auto v : vv[u]) {
		if(v == fa)	continue;
		dfs(v, u);
		for(int j=m; j>=a[u]; j--) {
			for(int k=1; j-k>=a[u]; k++) {
				dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k]);
			}
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == -1 && m == -1)	break;
		mes(dp, 0);
		for(int i=1, x; i<=n; i++) {
			scanf("%d%d", &x, &p[i]);
			a[i] = x/20;
			if(x % 20)	a[i]++;
			vv[i].clear();
		}
		for(int i=2, u, v; i<=n; i++) {
			scanf("%d%d", &u, &v);
			vv[u].push_back(v);
			vv[v].push_back(u);
		}
		if(m == 0) {
			printf("0\n");
			continue;
		}
		dfs(1, 0);
		// for(int i=1; i<=n; i++) {
		//     for(int j=1; j<=m; j++) {
		//         printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		//     }
		// }
		printf("%d\n", dp[1][m]);
	}
	return 0;
}

