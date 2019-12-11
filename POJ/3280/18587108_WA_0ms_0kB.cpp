/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月07日 星期四 22时58分02秒
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
const int    maxn = 2e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], c[maxn];
char s[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d%d", &m, &n);
	scanf("%s", s+1);
	for(int i=1; i<=m; i++) {
		char ss[5];
		scanf("%s", ss);
		int x, y;
		scanf("%d%d", &x, &y);
		c[ss[0]-'a'+1] = min(x, y);
	}
	mes(dp, inf);
	for(int i=1; i<=n; i++)	
		dp[i][i] = 0;
	for(int d=2; d<=n; d++) {
		for(int i=1, j=d; j<=n; i++, j++) {
			if(s[i] == s[j])
				dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = min(dp[i+1][j]+c[s[i]-'a'+1], dp[i][j-1]+c[s[j]-'a'+1]);
			// printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
