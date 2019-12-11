#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int dp[2005][2005];
long long int mod=1e9+7;

void handle() {
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=2000; i++)
		dp[1][i] = 1;
	for(int k=2; k<2002; k++) {
		for(int i=1; i<2002; i++) {
			if(!dp[k-1][i])
				continue;
			for(int j=1; j<=2002 / i; j++) {
				dp[k][i*j] = dp[k][i*j] + dp[k-1][i];
				dp[k][i*j] = dp[k][i*j] % mod;
			}
		}
	}
}

int main() {
	handle();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		long long int ans=0;
		for(int i=1; i<=n; i++) {
			ans += dp[m][i];
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}