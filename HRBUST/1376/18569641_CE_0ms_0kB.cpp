    > Created Time : 2019年03月06日 星期三 23时19分29秒
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

int a[maxn];
ll dp[maxn][maxn];

int main() {
	while(~scanf("%d", &n)) {
		m = 2*n;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			a[i+n] = a[i];
		}
		mes(dp, 0);
		for(int d=2; d<=n; d++) {
			for(int i=1, j=d; j<=m; i++, j++) {
				for(int k=i; k<j; k++) {
					dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
				}
				// printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
			}
		}
		ll ans = 0;
		for(int i=1; i<=m; i++) {
			ans = max(ans, dp[i][i+n-1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
