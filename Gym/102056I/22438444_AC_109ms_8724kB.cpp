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

ll a[maxn], b[maxn], c[maxn];
ll dp[2][maxn][5060];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		}
		mes(dp, 0);
		int f = 1;
		dp[f][1][n] = a[n];
		for(int i=n-1; i>=1; i--) {
			f = !f;
			int up = (i+n)*(n-i+1)/2;
			for(int j=1; j<=(n-i+1); j++) {
				for(int k=0; k<=up; k++) {
					dp[f][j][k] = 0;
					if(k>=i && dp[!f][j-1][k-i]) {
						dp[f][j][k] = max(dp[f][j][k], dp[!f][j-1][k-i] + a[i]);
					}
					if(dp[!f][j][k]) {
						dp[f][j][k] = max(dp[f][j][k], dp[!f][j][k] + (k-j*i)*b[i]);
						dp[f][j][k] = max(dp[f][j][k], dp[!f][j][k] + j*c[i]);
					}
				}
			}
		}
		int up = (1+n)*n/2;
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=up; j++) {
				ans = max(ans, dp[f][i][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
