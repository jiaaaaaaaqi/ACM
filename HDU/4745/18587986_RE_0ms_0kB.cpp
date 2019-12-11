/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月08日 星期五 00时35分40秒
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
const int    maxn = 1e3 + 10;
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
int dp[maxn][maxn];

int main() {
	while(scanf("%d", &m), m) {
		mes(a, 0);
		mes(dp, 0);
		for(int i=1; i<=m; i++) {
			scanf("%d", &a[i]);
			a[i+n] = a[i];
		}
		n = m<<1;
		for(int i=1; i<=n; i++) {
			dp[i][i] = 1;
		}
		for(int d=2; d<=n; d++) {
			for(int i=1, j=d; j<=n; i++, j++) {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
				if(a[i] == a[j])
					dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
			}
		}
		int ans = 0;
		for(int i=1; i<=m; i++) {
			ans = max(ans, dp[i][i+m-1]);
			ans = max(ans, dp[i][i+m-2]+1);
		}
		cout << ans << endl;
	}
	return 0;
}
