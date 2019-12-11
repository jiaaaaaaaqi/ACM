/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月27日 星期三 12时30分46秒
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
const int    maxn = 11;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int cost[maxn], love[maxn][maxn], b[maxn][maxn];
ll val[1<<maxn][maxn], dp[1<<maxn][maxn];

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		for(int i=1; i<=m; i++) {
			scanf("%d", &cost[i]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d", &love[i][j]);
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		int mx = (1<<n)-1;
		for(int s=0; s<=mx; s++) {
			for(int i=1; i<=m; i++) {
				val[s][i] = 0;
				for(int j=1; j<=n; j++) {
					if(s & (1<<(j-1))) {
						val[s][i] += love[j][i];
						val[s][i] -= cost[i];
						for(int k=j+1; k<=n; k++) {
							if(s & (1<<(k-1))) {
								val[s][i] += b[j][k];
							}
						}
					}
				}
			}
		}
		// for(int s=0; s<=mx; s++) {
		//     for(int i=1; i<=m; i++) {
		//         printf("dp[%d][%d] = %d\n", s, i, val[s][i]);
		//     }
		// }
		for(int i=0; i<=mx; i++) {
			for(int j=1; j<=m; j++) {
				dp[i][j] = -INF;
			}
		}
		for(int i=0; i<=mx; i++) {
			dp[i][1] = val[i][1];
		}
		for(int i=1; i<m; i++) {
			for(int s=0; s<=mx; s++) {
				for(int k=s; k; k=(k-1)&s) {
					dp[k][i+1] = max(dp[k][i+1], dp[s][i]+val[k][i+1]);
				}
			}
		}
		ll ans = -INF;
		for(int i=0; i<=mx; i++) {
			ans = max(ans, dp[i][m]);
		}
		if(ans > 0)
			cout << ans << endl;
		else
			cout << "STAY HOME" << endl;
	}
	return 0;
}

