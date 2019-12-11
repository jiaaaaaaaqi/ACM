/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月28日 星期四 15时44分23秒
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
const int    maxn = 19;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll dp[1<<maxn][maxn];
bool maps[maxn][maxn];

int main() {
	while(~scanf("%d%d", &n, &m)) {
		mes(maps, 0);
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			maps[u][v] = maps[v][u] = true;
		}
		mes(dp, 0);
		for(int i=1; i<=n; i++) {
			if(maps[1][i]) {
				dp[1|(1<<(i-1))][i] = 1;
			}
		}
		int mx = (1<<n)-1;
		for(int i=1; i<mx; i++) {
			for(int j=1; j<=n; j++) {
				if(!(i&(1<<(j-1))))	continue;
				for(int k=1; k<=n; k++) {
					if(maps[j][k] && !(i&(1<<(k-1)))) {
						dp[i|(1<<(k-1))][k] += dp[i][j];
					}
				}
			}
		}
		ll ans = 0;
		for(int i=2; i<=n; i++) {
			if(maps[i][1]) {
				ans += dp[mx][i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

