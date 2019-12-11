/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月29日 星期五 00时36分48秒
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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll dp[maxn], sum[maxn];
int q[maxn], a[maxn];

ll getup(int i, int j) {
	return (dp[i]+sum[i]*sum[i]) - (dp[j]+sum[j]*sum[j]);
}

ll getdown(int i, int j) {
	return sum[i] - sum[j];
}

ll getdp(int i, int j) {
	return dp[j] + (sum[i]-sum[j])*(sum[i]-sum[j]) + m;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		sum[0] = 0;
		for(int i=1; i<=n; i++)	dp[i] = INF;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		int head, tail;
		head = tail = 0;
		q[tail] = 0;
		for(int i=1; i<=n; i++) {
			while(head < tail && getup(q[head+1], q[head]) <= 2*sum[i]*getdown(q[head+1], q[head]))
				head++;
			dp[i] = getdp(i, head);
			while(head < tail && getup(q[tail], q[tail-1]) * getdown(i, q[tail]) <= getup(i, q[tail]) * getdown(q[tail], q[tail-1]))
				tail--;
			q[++tail] = i;
		}
		cout << dp[n] << endl;
	}
	return 0;
}

