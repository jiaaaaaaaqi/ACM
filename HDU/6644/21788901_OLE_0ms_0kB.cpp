/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Tue 17 Sep 2019 11:45:48 PM CST
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, q;
int cas, tol, T;

ll k;
char s[maxn];
char t[maxn];
ll dp[maxn][10][30];

void solve(int n) {
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<m; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	{
		mes(dp[n], 0);
		if(s[n] != '?') {
			dp[n][s[n]-'0'][(s[n]-'0')%m] = 1;
		} else {
			for(int x=0; x<=9; x++) {
				dp[n][x][x%m] = 1;
			}
		}
	}
	int base = 10%m;
	for(int i=n-1; i>=1; i--) {
		mes(dp[i], 0);
		if(s[i] != '?') {
			int x = s[i]-'0';
			for(int j=0; j<=9; j++) {
				for(int k=0; k<m; k++) {
					dp[i][x][(x*base+k)%m] += dp[i+1][j][k];
				}
			}
		} else {
			for(int x=0; x<=9; x++) {
				for(int j=0; j<=9; j++) {
					for(int k=0; k<m; k++) {
						dp[i][x][(x*base+k)%m] += dp[i+1][j][k];
					}
				}
			}
		}
		base = base*10%m;
		// for(int j=0; j<=9; j++) {
		//     for(int k=0; k<m; k++) {
		//         if(dp[i][j][k] > INF)	return ;
		//     }
		// }
	}
}

void debug(int len) {
	for(int i=1; i<=len; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<m; k++) {
				if(dp[i][j][k])
					printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
			}
		}
	}
	return ;
}

ll base[maxn];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &q);
		scanf("%s", s+1);
		int len = strlen(s+1);
		solve(len);
		// debug(len);
		base[len+1] = 1;
		for(int i=len; i>=1; i--)	base[i] = base[i+1]*10%m;
		while(q--) {
			scanf("%lld", &k);
			int flag = 0;
			for(int j=0; j<=9; j++) {
				if(dp[1][j][0] >= k) {
					flag = 1;
					break;
				}
			}
			if(!flag) {
				printf("-1\n");
				continue;
			}
			int tmp = 0;
			for(int i=1; i<=n; i++) {
				if(s[i] != '?') {
					t[i] = s[i];
				} else {
					for(int j=0; j<=9; j++) {
						int need = (2*m - ((tmp*10+j)%m*base[i]%m))%m;
						if(k <= dp[i][j][need]) {
							t[i] = j+'0';
							break;
						} else {
							k -= dp[i][j][need];
						}
					}
				}
				tmp = (tmp*10+t[i]-'0')%m;
			}
			t[n+1] = '\0';
			printf("%s\n", t+1);
		}
	}
	return 0;
}

