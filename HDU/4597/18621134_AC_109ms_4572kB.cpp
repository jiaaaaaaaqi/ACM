
/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月09日 星期六 14时26分03秒
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
const int    maxn = 2e1 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], b[maxn];
int sum1[maxn], sum2[maxn];
int dp[maxn][maxn][maxn][maxn];

void dfs(int i, int ii, int j, int jj) {
	if(dp[i][ii][j][jj])	return ;
	if(i <= ii) {
		dfs(i+1, ii, j, jj);
		dp[i][ii][j][jj] = max(dp[i][ii][j][jj], sum1[ii]-sum1[i]+sum2[jj]-sum2[j-1]-dp[i+1][ii][j][jj]+a[i]);
		dfs(i, ii-1, j, jj);
		dp[i][ii][j][jj] = max(dp[i][ii][j][jj], sum1[ii-1]-sum1[i-1]+sum2[jj]-sum2[j-1]-dp[i][ii-1][j][jj]+a[ii]);
	}
	if(j <= jj) {
		dfs(i, ii, j+1, jj);
		dp[i][ii][j][jj] = max(dp[i][ii][j][jj], sum1[ii]-sum1[i-1]+sum2[jj]-sum2[j]-dp[i][ii][j+1][jj]+b[j]);
		dfs(i, ii, j, jj-1);
		dp[i][ii][j][jj] = max(dp[i][ii][j][jj], sum1[ii]-sum1[i-1]+sum2[jj-1]-sum2[j-1]-dp[i][ii][j][jj-1]+b[jj]);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		tol = 0;
		mes(dp, 0);
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]), sum1[i] = sum1[i-1] + a[i];
		for(int i=1; i<=n; i++)	scanf("%d", &b[i]), sum2[i] = sum2[i-1] + b[i];
		dfs(1, n, 1, n);
		// for(int i=1; i<=n; i++) {
		//     for(int ii=1; ii<=n; ii++) {
		//         for(int j=1; j<=n; j++) {
		//             for(int jj=1; jj<=n; jj++) {
		//                 printf("dp[%d][%d][%d][%d] = %d\n", i, ii, j, jj, dp[i][ii][j][jj]);
		//             }
		//         }
		//     }
		// }
		cout << dp[1][n][1][n] << endl;
	}
	return 0;
}
