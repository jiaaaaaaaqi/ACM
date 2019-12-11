/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月18日 星期一 14时52分08秒
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
const int    maxn = 2e1 + 1;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

double dp[1<<maxn], p[maxn];

int main() {
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%lf", &p[i]);
		}
		int mx = (1<<n)-1;
		dp[mx] = 0;
		for(int i=mx-1; i>=0; i--) {
			double a, b;
			a = b = 0.0;
			for(int j=1; j<=n; j++) {
				if(i & (1<<(j-1)))	continue;
				a += p[j]*dp[i|(1<<(j-1))];
				b += p[j];
			}
			dp[i] = (a+1)/b;
		}
		printf("%.5f\n", dp[0]);
	}
	return 0;
}

