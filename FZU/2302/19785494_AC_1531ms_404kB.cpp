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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], b[maxn*2], q[maxn];
int sum[maxn], dp[maxn][maxn];

ll getup(int i, int j, int k) {
	return (dp[i][k-1]-dp[j][k-1]) + (sum[i]*sum[i]-sum[j]*sum[j]);
}

ll getdown(int i, int j) {
	return (sum[i]-sum[j]) * 2;
}

ll getdp(int i, int j) {
	return (sum[i]-sum[j]) * (sum[i]-sum[j]);
}

int solve() {
	mes(dp, 0);
	sum[0] = 0;
	for(int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + a[i];
		dp[i][1] = sum[i]*sum[i];
	}
	for(int k=2; k<=m; k++) {
		int head, tail;
		head = 0, tail = -1;
		q[++tail] = k-1;
		for(int i=k; i<=n; i++) {
			while(head+1<=tail && getup(q[head+1], q[head], k) <= sum[i] * getdown(q[head+1], q[head]))
				head++;
			if(i>=k)
				dp[i][k] = dp[q[head]][k-1] + getdp(i, q[head]);
			while(head+1<=tail && getup(q[tail], q[tail-1], k)*getdown(i, q[tail]) >= getup(i, q[tail], k)*getdown(q[tail], q[tail-1]))
				tail--;
			q[++tail] = i;
		}
	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=m; j++) {
//			printf("dp[%d][%d] = %d%c", i, j, dp[i][j], j==m ? '\n' : '\t');
//		}
//	}
	return dp[n][m];
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
			b[i+n] = b[i];
		}
		int ans = inf;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				a[j] = b[i+j-1];
			}
			ans = min(ans, solve());
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
1
5 3
2 3 8 2 5
*/
