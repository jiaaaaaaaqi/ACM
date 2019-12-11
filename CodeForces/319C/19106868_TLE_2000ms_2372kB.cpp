/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019/4/5 21:25:29
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn], b[maxn], dp[maxn];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=1; i<=n; i++) scanf("%d", &b[i]);
	for(int i=1; i<=n; i++) {
		dp[i] = INF;
	}
	dp[1] = 0;
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i] = min(dp[i], dp[j] + a[i]*b[j]);
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}

