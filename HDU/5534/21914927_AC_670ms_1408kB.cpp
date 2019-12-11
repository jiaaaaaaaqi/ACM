/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年09月25日 星期三 16时01分31秒
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 3e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 1e9;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int dp[2][maxn];
int a[maxn];

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<n; i++) {
			scanf("%d", &a[i]);
		}
		ll tmp = a[1]*n;
		n -= 2;

		int f = 0;
		// for(int i=0; i<=n; i++) {
		//     dp[0][i] = i*a[1];
		// }

		for(int i=0; i<=n; i++) {
			dp[0][i] = i*(a[2]-a[1]);
		}
		for(int i=2; i<=n; i++) {
			f = !f;
			// for(int j=0; j<=n; j++) {
			//     printf("dp[%d][%d] = %d\n", i-1, j, dp[!f][j]);
			// }
			for(int j=0; j<=n; j++) dp[f][j] = -inf;
			for(int j=0; j<=n; j++) {
				int up = (n-j)/i;
				for(int k=0; k<=up; k++) {
					dp[f][j+k*i] = max(dp[f][j+k*i], dp[!f][j] + k*(a[i+1]-a[1]));
				}
			}
		}
		// for(int j=0; j<=n; j++) {
		//     printf("dp[%d][%d] = %d\n", n, j, dp[!f][j]);
		// }

		int ans = dp[f][n];
		ans += tmp;
		printf("%d\n", ans);

	}
    return 0;
}

