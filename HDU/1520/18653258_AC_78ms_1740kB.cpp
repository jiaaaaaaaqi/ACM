/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月11日 星期一 00时10分37秒
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
const int    maxn = 6e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], dp[maxn][2];
bool vis[maxn];
vector<int> vv[maxn];

void dfs(int u) {
	bool flag = false;
	for(auto v : vv[u]) {
		flag = true;
		dfs(v);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			vv[i].clear();
			dp[i][0] = 0;
			dp[i][1] = a[i];
		}
		int x, y;
		while(scanf("%d%d", &x, &y), x||y) {
			vis[x] = true;
			vv[y].push_back(x);
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				dfs(i);
				cout << max(dp[i][1], dp[i][0]) << endl;
				break;
			}
		}
		// for(int i=1; i<=n; i++) {
		//     printf("dp[%d][0] = %d\n", i, dp[i][0]);
		//     printf("dp[%d][1] = %d\n", i, dp[i][1]);
		// }
	}
	return 0;
}
