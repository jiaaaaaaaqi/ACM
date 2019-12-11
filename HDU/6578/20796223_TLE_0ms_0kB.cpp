/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月26日 星期五 15时09分38秒
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
const int    maxn = 105;
const int    maxm = 1e5 + 10;
const ll     mod  = 998244353;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int l, r, d;
	bool operator < (Node a) const {
		return r<a.r;
	}
} node[maxn];
ll dp[maxn][maxn][maxn][2];

bool check(int d1, int d2, int d3, int d4, Node &x) {
	int l=x.l, r=x.r, d=x.d, cnt=0;
	if(l<=d1 && d1<=r)	cnt++;
	if(l<=d2 && d2<=r)	cnt++;
	if(l<=d3 && d3<=r)	cnt++;
	if(l<=d4 && d4<=r)	cnt++;
	if(cnt == d)	return true;
	else	return false;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &node[i].l, &node[i].r, &node[i].d);
		}
		sort(node+1, node+1+m);
		int f = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					dp[i][j][k][f] = 0;
				}
			}
		}
		dp[0][0][0][f] = 4;
		int ask = 1;
		for(int o=1; o<=n; o++) {
			{
				while(ask<=m && node[ask].r == o) {
					for(int i=0; i<=o; i++) {
						for(int j=0; j<=o; j++) {
							for(int k=0; k<=o; k++) {
								if(!dp[i][j][k][f])	continue;
								if(!check(i, j, k, o, node[ask])) {
									dp[i][j][k][f] = 0;
								}
							}
						}
					}
					ask++;
				}
			}
			if(o == n)	break;
			f = !f;
			for(int i=0; i<=o; i++) {
				for(int j=0; j<=o; j++) {
					for(int k=0; k<=o; k++) {
						dp[i][j][k][f] = 0;
					}
				}
			}
			for(int i=0; i<=o; i++) {
				for(int j=0; j<=o; j++) {
					for(int k=0; k<=o; k++) {
						if(!dp[i][j][k][!f])	continue;
						dp[j][k][o][f] = (dp[j][k][o][f] + dp[i][j][k][!f])%mod;
						dp[i][k][o][f] = (dp[i][k][o][f] + dp[i][j][k][!f])%mod;
						dp[i][j][o][f] = (dp[i][j][o][f] + dp[i][j][k][!f])%mod;
						dp[i][j][k][f] = (dp[i][j][k][f] + dp[i][j][k][!f])%mod;
					}
				}
			}
		}
		ll ans = 0;
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				for(int k=0; k<=n; k++) {
					if(dp[i][j][k][f]) {
						ans = (ans + dp[i][j][k][f])%mod;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

