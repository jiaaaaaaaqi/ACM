#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;

int n, m;
int wei[maxn];
int val[maxn];
int dp[maxn];

void init() {
	memset(dp, 0, sizeof(dp));
	memset(wei, 0, sizeof(wei));
	memset(val, 0, sizeof(val));
}

int solve() {
	for(int i=1; i<=n; i++) {
		for(int j=m; j>=wei[i]; j--) {
			dp[j] = max(dp[j - wei[i]] + val[i], dp[j]);
		}
	}
	return dp[m];
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &wei[i], &val[i]);
		}
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
