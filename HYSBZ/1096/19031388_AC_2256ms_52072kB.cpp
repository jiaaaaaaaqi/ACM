/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月01日 星期一 16时08分59秒
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

int n, m;
int cas, tol, T;

int q[maxn];
ll p[maxn], v[maxn], w[maxn], f[maxn], g[maxn];
ll dp[maxn];

ll getup(int i, int j) {
	return (dp[i]+g[i]) - (dp[j]+g[j]);
}

ll getdown(int i, int j) {
	return f[i]-f[j];
}

ll getdp(int i, int j) {
	return p[i]*(f[i]-f[j]) - g[i] + g[j] + w[i];
}

int main() {
	scanf("%d", &n);
	p[0] = v[0] = w[0] = 0;
	f[0] = g[0] = 0;
	for(int i=1; i<=n; i++) {
		scanf("%lld%lld%lld", &p[i], &v[i], &w[i]);
		f[i] = f[i-1] + v[i];
		g[i] = g[i-1] + p[i]*v[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	// for(int i=1; i<=n; i++) {
	//     for(int j=0; j<i; j++) {
	//         dp[i] = min(dp[i], dp[j]+p[i]*(f[i]-f[j])-g[i]+g[j]+w[i]);			
	//     }
	//     printf("dp[%d] = %lld\n", i, dp[i]);
	// }
	int head, tail;
	head = tail = 0;
	q[0] = 0;
	for(int i=1; i<=n; i++) {
		while(head<tail && getup(q[head+1], q[head]) <= p[i]*getdown(q[head+1], q[head]))
			head++;
		dp[i] = dp[q[head]] + getdp(i, q[head]);
		while(head<tail && getup(q[tail], q[tail-1])*getdown(i, q[tail]) >= getup(i, q[tail])*getdown(q[tail], q[tail-1])) 
			tail--;
		q[++tail] = i;
		// printf("%d dp[%d] = %lld\n", q[head], i, dp[i]);
	}
	printf("%lld\n", dp[n]);
	return 0;
}

