#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mx = 1e5+5;
ll num1[mx][2];
ll num2[mx][2];

ll dp[mx][2];

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int n, l0, l1, s0, s1;
		ll x;
		scanf("%d%d%d%d%d", &n, &l0, &l1, &s0, &s1);
		for (int i = 1; i < n; i++) {
			scanf("%lld", &x);
			num1[i][0] = x;
		}
		for (int i = 1; i < n; i++) {
			scanf("%lld", &x);
			num1[i][1] = x;
		}
		for (int i = 1; i < n; i++) {
			scanf("%lld", &x);
			num2[i][0] = x;
		}
		for (int i = 1; i < n; i++) {
			scanf("%lld", &x);
			num2[i][1] = x;
		}
		dp[1][0] = l0;
		dp[1][1] = l1;
		for (int i = 2; i <= n; i++) {
			//printf("num: %d %d %d %d\n", num1[i-1][0], num2[i-1][0], num1[i-1][1], num2[i-1][1]);
			dp[i][0] = min(dp[i-1][0] + num1[i-1][1], dp[i-1][1] + num2[i-1][0]);
			dp[i][1] = min(dp[i-1][1] + num2[i-1][1], dp[i-1][0] + num1[i-1][0]);
			//printf("i = %d dp[i][0] = %lld dp[i][1] = %lld\n", i, dp[i][0], dp[i][1]);
		}
		//printf("%lld %lld\n", dp[n][0], dp[n][1]);
		ll ans = min(dp[n][0] + s0, dp[n][1] + s1);
		printf("%lld\n", ans);
	}
	return 0;
} 