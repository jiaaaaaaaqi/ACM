#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 15;
const int maxm = 600;
const int mod = 100000000;
using namespace std;

int n, m, tol;
int dp[maxn][maxm];
int cur[maxn];
int state[maxn];

void init() {
	tol = 0;
	memset(dp, 0, sizeof dp);
	memset(cur, 0, sizeof cur);
	for(int i=0; i<(1<<m); i++) {
		if(i & (i << 1))
			continue;
		else
			state[++tol] = i;
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				int x;
				scanf("%d", &x);
				if(x == 0)
					cur[i] |= (1 << (m - j));
			}
		}
		for(int i=1; i<=tol; i++) {
			if(state[i] & cur[1]) continue;
			else	dp[1][state[i]] = 1;
		}
		for(int i=2; i<=n; i++) {
			for(int k=1; k<=tol; k++) {
				if(state[k] & cur[i])	continue;
				for(int j=1; j<=tol; j++) {
					if(state[j] & cur[i - 1])	continue;
					if(state[j] & state[k])	continue;
					dp[i][state[k]] += dp[i-1][state[j]];
					dp[i][state[k]] %= mod;
				}
			}
		}
		ll ans = 0;
		for(int i=1; i<=tol; i++) {
			if(state[i] & cur[n])	continue;
			ans += dp[n][state[i]];
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
