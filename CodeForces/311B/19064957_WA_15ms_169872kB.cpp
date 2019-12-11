/**************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月03日 星期三 13时27分27秒
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

int q[maxn];
ll d[maxn], a[maxn], sum[maxn], dp[105][maxn];

ll getup(int i, int j, int k) {
	return (dp[i-1][j]+sum[j]) - (dp[i-1][k]+sum[k]);
}

ll getdown(int j, int k) {
	return j-k;
}

ll getdp(int i, int j, int k) {
	return dp[i-1][k] + a[j]*(j-k) - sum[j]+sum[k];
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	d[1] = 0;
	for(int i=2; i<=n; i++) {
		scanf("%I64d", &d[i]);
		d[i] += d[i-1];
	}
	for(int i=1; i<=m; i++) {
		ll x, t;
		scanf("%I64d%I64d", &x, &t);
		a[i] = t-d[x];
	}
	sort(a+1, a+1+m);
	sum[0] = 0;
	for(int i=1; i<=m; i++) {
		sum[i] = sum[i-1] + a[i];
		for(int j=1; j<=k; j++) {
			dp[j][i] = INF;
		}
	}
	for(int i=1; i<=m; i++) {
		dp[1][i] = a[i]*i - sum[i];
	}
	for(int i=2; i<=k; i++) {
		int head, tail;
		head = tail = 0;
		q[0] = i-1;
		for(int j=i; j<=m; j++) {
			while(head<tail && getup(i, q[head+1], q[head]) <= a[i]*getdown(q[head+1], q[head]))
				head++;
			dp[i][j] = getdp(i, j, q[head]);
			while(head<tail && getup(i, q[tail], q[tail-1])*getdown(j, q[tail]) >= getup(i, j, q[tail])*getdown(q[tail], q[tail-1]))
				tail--;
			q[++tail] = j;
			// printf("%d dp[%d][%d] = %I64d\n", q[head], i, j, dp[i][j]);
		}
	}
	printf("%I64d\n", dp[k][m]);
	return 0;
}

