/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月12日 星期二 00时29分24秒
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
const int    maxn = 3e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector< pii > vv[maxn];
int a[maxn], sz[maxn], dp[maxn][maxn];

void dfs(int u) {
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi, w = vv[u][i].se;
		dfs(v);
		sz[u] += sz[v];
		for(int j=sz[u]; j>=0; j--) {
			for(int k=0; k<=j; k++) {
				dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k]-w);
			}
		}
	}
	sz[u]++;
}

int main() {
	mes(sz, 0);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		dp[i][0] = 0;
		for(int j=1; j<=m; j++) {
			dp[i][j] = -inf;
		}
	}
	for(int u=1, k; u<=n-m; u++) {
		scanf("%d", &k);
		for(int j=1, v, w; j<=k; j++) {
			scanf("%d%d", &v, &w);
			vv[u].push_back(make_pair(v, w));
		}
	}
	for(int i=n-m+1; i<=n; i++) {
		scanf("%d", &a[i]);
		dp[i][1] = a[i];
	}
	dfs(1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			printf("%d%c", dp[i][j], j==m ? '\n' : ' ');
		}
	}
	// for(int i=m; i>=0; i--) {
	//     if(dp[1][i] >= 0) {
	//         printf("%d\n", i);
	//         return 0;
	//     }
	// }
	return 0;
}

