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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
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
struct DP{
	int n, v;
	DP () {
		n = v = 0;
	}
	DP (int _n, int _v) {
		n = _n, v = _v;
	}
	bool operator<(DP a) const {
		if(n == a.n) {
			return v<a.v;
		} else {
			return n<a.n;
		}
	}
} dp[55][maxn];

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int sum = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int mx = min(m-1, sum);
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=mx; j++) {
				dp[i][j] = DP(0, 0);
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=a[i]; j++) {
				dp[i][j] = DP(dp[i-1][j].n, dp[i-1][j].v);
			}
			for(int j=a[i]; j<=mx; j++) {
				dp[i][j] = DP(dp[i-1][j].n, dp[i-1][j].v);
				DP d = dp[i-1][j-a[i]];
				d.n++, d.v += a[i];
				if(dp[i][j] < d) {
					dp[i][j] = DP(d.n, d.v);
				}
//				printf("dp[%d][%d] = %d %d\n", i, j, dp[i][j].n, dp[i][j].v);
			}
		}
		dp[n][mx].n++;
		dp[n][mx].v += 678;
		printf("Case %d: %d %d\n", cas++, dp[n][mx].n, dp[n][mx].v);
	}
	return 0;
}
