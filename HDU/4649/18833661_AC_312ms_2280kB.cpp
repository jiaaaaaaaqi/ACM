/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月20日 星期三 15时46分40秒
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
const int    maxn = 2e2 + 10;
const int    maxm = 21;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
char s[maxn];
double dp[2][1<<maxm], p[maxn];

void init() {
	for(int i=1; i<=n; i++) {
		a[i] = 0;
		p[i] = 0.0;
	}
}

int main() {
	cas = 1;
	char cc[11];
	while(~scanf("%d", &n)) {
		init();
		int st;
		scanf("%d", &st);
		int mx = (int)log2(1.0*st)+1;
		for(int i=1; i<=n; i++)	{
			scanf("%d", &a[i]);
			mx = max(mx, (int)log2(1.0*a[i])+1);
		}
		for(int i=1; i<=n; i++)	{
			scanf("%s", cc+1);
			s[i] = cc[1];
		}
		for(int i=1; i<=n; i++)		
			scanf("%lf", &p[i]);
		mx = (1<<mx)-1;
		for(int j=0; j<=mx; j++)	
			dp[0][j] = 0.0;
		int flag = 0;
		dp[0][st] = 1.0;
		for(int i=1; i<=n; i++) {
			flag = !flag;
			for(int j=0; j<=mx; j++)	dp[flag][j] = 0.0;
			for(int j=0; j<=mx; j++) {
				if(dp[!flag][j] == 0)	continue;
				if(s[i] == '^') {
					dp[flag][j] += dp[!flag][j] * p[i];
					dp[flag][j^a[i]] += dp[!flag][j] * (1.0-p[i]);
				} else if(s[i] == '&') {
					dp[flag][j] += dp[!flag][j] * p[i];
					dp[flag][j&a[i]] += dp[!flag][j] * (1.0-p[i]);
				} else {
					dp[flag][j] += dp[!flag][j] * p[i];
					dp[flag][j|a[i]] += dp[!flag][j] * (1.0-p[i]);
				}
			}
		}
		double ans = 0.0;
		for(int i=0; i<=mx; i++) {
			ans += 1.0*i*dp[flag][i];
		}
		printf("Case %d:\n", cas++);
		printf("%.6f\n", ans);
	}
	return 0;
}

