/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 03:24:38 PM CST
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

int a[maxn];
double dp[2][maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);
	double ans = 0.0;
	dp[0][0] = 1.0;
	for(int i=1; i<=n; i++) {
		int f = i%2;
		for(int j=0; j<=i;j++)	dp[f][j] = 0.0;
		for(int j=0; j<i; j++)	dp[f][j+1] += dp[!f][j]*a[i]/100.0;
		for(int j=0; j<i; j++)	dp[f][j] += dp[!f][j]*(100-a[i])/100.0;
		double res = 0.0;
		for(int j=1; j<=i; j++) {
			res += dp[f][j] * pow(j, 1.0*j/i);
		}
		ans = max(ans, res);
	}
	printf("%.9f\n", ans);
	return 0;
}

