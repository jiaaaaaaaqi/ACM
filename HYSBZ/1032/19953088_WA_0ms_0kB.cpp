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
const int    maxn = 5e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m, k;
int cas, tol, T;

int a[maxn];
int dp[maxn][maxn];

int main() {
	while(~scanf("%d", &n)) {
		mes(a, 0), mes(dp, inf);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=1; i<=n; i++)	dp[i][i] = 2;
		for(int d=2; d<=n; d++) {
			for(int i=1; i+d-1<=n; i++) {
				int l = i, r = i+d-1;
				bool flag = false;
				for(int j=l; j<=r; j++) {
					if(a[j] != a[l]) {
						flag = true;
						break;
					}
				}
				if(flag) {
					for(int j=l; j<r; j++) {
						dp[l][r] = min(dp[l][r], dp[l][j]+dp[j+1][r]);
					}
					if(a[l]==a[r]) {
						for(int j=l, c1=1; j<=min(l+2, r); j++, c1++) {
							if(a[j] != a[l])	break;
							for(int k=r, c2=1; k>=max(l, r-2); k--, c2++) {
								if(a[k] != a[r])	break;
								dp[l][r] = min(dp[l][r], dp[j+1][k-1]+max(0, 3-c1-c2));
							}
						}
					}
				} else {
					dp[l][r] = 1;
				}
//				printf("dp[%d][%d] = %d\n", l, r, dp[l][r]);
			}
		}
		printf("%d\n", dp[1][n]);
	}
    return 0;
}
