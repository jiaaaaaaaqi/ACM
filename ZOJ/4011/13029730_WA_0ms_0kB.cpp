#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long int dp[2005];
long long int mod=1000000007;

void init() {
	memset(dp, 0, sizeof(dp));
}

int main() {
	int T;
	scanf("%d", &T); 
	while(T--) {
		init();
		int n,m;
		scanf("%d%d",&n, &m);
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				if(j%i == 0) {
					dp[j]++;
				}
			}
		}
		/*
		for(int k=2; k<m; k++) {
			for(int i=n; i>=1; i--) {
				long long int ans=0;
				for(int j=1; j<=i; j++) {
					if(i%j == 0){
						ans += dp[j];
						if(ans >= mod)
							ans -= mod;
					}
				}
				dp[i]=ans;
			}
		}*/
		long long int ans=0;
		for(int i=1; i<=n; i++) {
			ans += dp[i];
			if(ans >= mod)
				ans -= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}