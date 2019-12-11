/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月19日 星期二 00时31分01秒
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
const int    maxn = 14;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn];
bool maps[maxn][maxn];
ll dp[1<<maxn][maxn][maxn], num[1<<maxn][maxn][maxn];

void init() {
	mes(a, 0);
	mes(maps, 0);
	int mx = (1<<n)-1;
	for(int i=0; i<=mx; i++) {
		for(int j=0; j<=n; j++) {
			for(int k=0; k<=n; k++) {
				dp[i][j][k] = 0;
				num[i][j][k] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i=1; i<=n; i++)	scanf("%lld", &a[i]);
		a[0] = 0;
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			maps[u][v] = maps[v][u] = 1;
		}
		for(int i=1; i<=n; i++) {
			dp[1<<(i-1)][0][i] = a[i];
			num[1<<(i-1)][0][i] = 1;
			maps[0][i] = 1;
		}
		int mx = (1<<n)-1;
		for(int i=1; i<=mx; i++) {
			for(int l2=0; l2<=n; l2++) {
				for(int l1=1; l1<=n; l1++) {
					if(!dp[i][l2][l1])	continue;
					if(!maps[l2][l1])	continue;
					for(int l0=1; l0<=n; l0++) {
						if(!maps[l1][l0])	continue;
						if(i & (1<<(l0-1)))	continue;
						int now = i | (1<<(l0-1));
						ll tmp = (dp[i][l2][l1] + a[l0] + a[l0]*a[l1]);
						if(maps[l2][l0])	tmp += a[l2]*a[l1]*a[l0];
						if(dp[now][l1][l0] < tmp) {
							dp[now][l1][l0] = tmp;
							num[now][l1][l0] = num[i][l2][l1];
						} else if(dp[now][l1][l0] == tmp) {
							num[now][l1][l0] += num[i][l2][l1];
						}
					}
				}
			}
		}
		ll ans = 0, tol = 0;
		for(int i=0; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(!maps[i][j])	continue;
				if(ans < dp[mx][i][j]) {
					ans = dp[mx][i][j];
					tol = num[mx][i][j];
				} else if(ans == dp[mx][i][j]) {
					tol += num[mx][i][j];
				}
			}
		}
		printf("%lld %lld\n", ans, n==1 ? tol : tol>>1);
	}
	return 0;
}
