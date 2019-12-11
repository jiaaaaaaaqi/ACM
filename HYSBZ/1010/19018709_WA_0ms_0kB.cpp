/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月31日 星期日 15时18分13秒
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
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn], sum[maxn], dp[maxn];
int q[maxn];

ll getup(int i, int j) {
	return -1ll*i-1ll*j-sum[i]-sum[j];
}

ll getdp(int i, int j) {
	ll tmp = 1ll*i-1ll*j-1ll+sum[i]-sum[j];
	return (tmp-m)*(tmp-m);
}

int main() {
	scanf("%d%d", &n, &m);
	sum[0] = 0;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	int head, tail;
	head = tail = 0;
	q[0] = 0;
	for(int i=1; i<=n; i++) {
		while(head<tail && getup(q[head+1], q[head]) >= 2ll*(m-i-sum[i]+1))
			head++;
		dp[i] = getdp(i, q[head]) + dp[q[head]];
		// printf("%d dp[%d] = %d\n", q[head], i, dp[i]);
		while(head<tail && getup(q[tail], q[tail-1]) >= getup(i, q[tail]))
			tail--;
		q[++tail] = i;
	}
	printf("%lld\n", dp[n]);
	return 0;
}

