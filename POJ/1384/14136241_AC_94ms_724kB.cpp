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
int val[505];
int wei[505];
int dp[10005];

void init() {
	memset(val, 0, sizeof(val));
	memset(wei, 0, sizeof(wei));
	memset(dp, inf, sizeof(dp));
}

int solve() {
	dp[0] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=wei[i]; j<=m; j++) {
			dp[j] = min(dp[j - wei[i]] + val[i], dp[j]);
		}
	}
	return dp[m];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int pre1, pre2;
		scanf("%d%d", &pre1, &pre2);
		m = pre2 - pre1;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &val[i], &wei[i]);
		}
		int ans = solve();
		if(ans == inf)	printf("This is impossible.\n");
		else	printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
	}
	return 0;
}
