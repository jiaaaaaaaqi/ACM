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
int q[maxn];

ll getup(int i, int j) {
	return dp[i]-dp[j];
}

ll getdown(int i, int j) {
	return b[j]-b[i];
}

ll getdp(int i, int j) {
	return dp[j] + a[i]*b[j];
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%I64d", &a[i]);
	for(int i=1; i<=n; i++) scanf("%I64d", &b[i]);
	for(int i=1; i<=n; i++) {
		dp[i] = INF;
	}
	dp[1] = 0;
	int head, tail;
	head = tail = 0;
	q[0] = 1;
	for(int i=2; i<=n; i++) {
		while(head<tail && getup(q[head+1], q[head]) <= a[i] * getdown(q[head+1], q[head]))
			head++;
		dp[i] = getdp(i, q[head]);
		while(head<tail && 1.0*getup(q[tail], q[tail-1])/getdown(q[tail], q[tail-1]) >= 1.0*getup(i, q[tail])/getdown(i, q[tail]))
		//while(head<tail && getup(q[tail], q[tail-1])*getdown(i, q[tail]) >= getdown(q[tail], q[tail-1])*getup(i, q[tail]))
			tail--;
		q[++tail] = i;
	}
	printf("%I64d\n", dp[n]);
	return 0;
}

