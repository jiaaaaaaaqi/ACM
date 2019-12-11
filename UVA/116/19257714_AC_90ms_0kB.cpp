/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月13日 星期六 15时52分34秒
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

ll dp[maxn][maxn];
string s[maxn][maxn];
int a[maxn][maxn];

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d", &a[i][j]);
				dp[i][j] = INF;
				s[i][j] = "";
				s[i][j] += '0'+250;
			}
		}
		for(int i=1; i<=n; i++) {
			dp[i][1] = a[i][1];
			s[i][1] = '0'+i;
		}
		char cc;
		for(int j=1; j<m; j++) {
			for(int i=1; i<=n; i++) {
				cc = '0'+i;
				if((dp[i][j]+a[i][j+1] < dp[i][j+1]) || (dp[i][j]+a[i][j+1]==dp[i][j+1] && s[i][j+1]>s[i][j]+cc)) {
					dp[i][j+1] = dp[i][j]+a[i][j+1];
					s[i][j+1] = s[i][j] + cc;
				}
				if(i==1) {
					cc = '0'+n;
					if((dp[i][j]+a[n][j+1] < dp[n][j+1]) || (dp[i][j]+a[n][j+1]==dp[n][j+1] && s[n][j+1]>s[i][j]+cc)) {
						dp[n][j+1] = dp[i][j] + a[n][j+1];
						s[n][j+1] = s[i][j] + cc;
					}
				} else {
					cc = '0'+i-1;
					if((dp[i][j]+a[i-1][j+1] < dp[i-1][j+1]) || (dp[i][j]+a[i-1][j+1]==dp[i-1][j+1] && s[i-1][j+1]>s[i][j]+cc)) {
						dp[i-1][j+1] = dp[i][j] + a[i-1][j+1];
						s[i-1][j+1] = s[i][j] + cc;
					}
				}
				if(i==n) {
					cc = '0'+1;
					if((dp[i][j]+a[1][j+1] < dp[1][j+1]) || (dp[i][j]+a[1][j+1]==dp[1][j+1] && s[1][j+1]>s[i][j]+cc)) {
						dp[1][j+1] = dp[i][j] + a[1][j+1];
						s[1][j+1] = s[i][j] + cc;
					}
				} else {
					cc = '0'+i+1;
					if((dp[i][j]+a[i+1][j+1] < dp[i+1][j+1]) || (dp[i][j]+a[i+1][j+1]==dp[i+1][j+1]&&s[i+1][j+1]>s[i][j]+cc)) {
						dp[i+1][j+1] = dp[i][j] + a[i+1][j+1];
						s[i+1][j+1] = s[i][j] + cc;
					}	
				}
			}
		}
		ll ans = INF;
		cc = '0'+250;
		string ss = "";
		ss += cc;
		for(int i=1; i<=n; i++) {
			if(ans > dp[i][m] || (ans==dp[i][m]&& ss>s[i][m])) {
				ans = dp[i][m];
				ss = s[i][m];
			}
		}
		for(int i=0; i<ss.length(); i++)
			printf("%d%c", ss[i]-'0', i==ss.length()-1 ? '\n' : ' ');
		printf("%lld\n", ans);
	}
	return 0;
}
