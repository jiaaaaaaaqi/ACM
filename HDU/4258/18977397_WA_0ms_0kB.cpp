/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月29日 星期五 00时53分47秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

int q[maxn];
ll a[maxn], dp[maxn];

ll getup(int i, int j) {
	return (dp[i]+a[i+1]*a[i+1]) - (dp[j]+a[j+1]*a[j+1]);
}

ll getdown(int i, int j) {
	return a[i+1] - a[j+1];
}

ll getdp(int i, int j) {
	return dp[j] + (a[i]-a[j+1])*(a[i]-a[j+1]) + m;
}

int main() {
	while(scanf("%lld%lld", &n, &m), n||m) {
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
			dp[i] = INF;
		}
		dp[0] = 0;
		int head, tail;
		head = tail = 0;
		q[0] = 0;
		for(int i=1; i<=n; i++) {
			while(head < tail && getup(q[head+1], q[head]) <= 2*a[i]*getdown(q[head+1], q[head]))
				head++;
			dp[i] = getdp(i, q[head]);
			while(head < tail && getup(q[tail], q[tail]-1)*getdown(i, q[tail]) >= getdown(q[tail], q[tail-1])*getup(i, q[tail]))
				tail--;
			q[++tail] = i;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

