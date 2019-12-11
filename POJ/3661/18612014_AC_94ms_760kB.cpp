/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月09日 星期六 13时52分08秒
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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], dp[maxn], sum[maxn];

int main() {
	mes(a, 0), mes(dp, 0), mes(sum, 0);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1];
		for(int k=1; k<=m; k++) {
			if(i-2*k < 0)	break;
			dp[i] = max(dp[i], dp[i-2*k]+sum[i-k]-sum[i-2*k]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}

