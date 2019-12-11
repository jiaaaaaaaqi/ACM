/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019/4/11 1:05:55
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

int n, m, ln, rn;
int cas, tol, T;

ll dp[maxn][maxn];
int a[maxn], gl[maxn], gr[maxn];
bool lt[maxn][maxn], rt[maxn][maxn];

void init() {
	mes(gl, 0), mes(gr, 0);
	mes(lt, 0), mes(rt, 0);
}

int main() {
	cas = 1;
	while(scanf("%d", &n), n) {
		init();
		scanf("%d", &m);
		for(int i=1; i<n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &ln);
		for(int i=1; i<=ln; i++) {
			scanf("%d", &gl[i]);
		}
		scanf("%d", &rn);
		for(int i=1; i<=rn; i++) {
			scanf("%d", &gr[i]);
		}
		for(int i=1; i<=ln; i++) {
			int t = gl[i];
			for(int j=1; j<n; j++) {
				lt[t][j] = true;
				t += a[j];
			}
			lt[t][n] = true;
		}
		for(int i=1; i<=rn; i++) {
			int t = gr[i];
			for(int j=n-1; j>=1; j--) {
				rt[t][j+1] = true;
				t += a[j];
			}
			rt[t][1] = true;
		}
		for(int i=0; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				dp[i][j] = INF;
			}
		}
		dp[m][n] = 0;
		for(int i=m-1; i>=0; i--) {
			for(int j=n; j>=1; j--) {
				dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
				if(lt[i][j] && i+a[j]<=m && j+1<=n)
					dp[i][j] = min(dp[i+a[j]][j+1], dp[i][j]);
				if(rt[i][j] && i+a[j-1]<=m && j-1>=1)	
					dp[i][j] = min(dp[i+a[j-1]][j-1], dp[i][j]);
			}
		}
		printf("Case Number %d: ", cas++);
		if(dp[0][1] <= m)
			printf("%lld\n", dp[0][1]);
		else
			printf("impossible\n");
	}
	return 0;
}

