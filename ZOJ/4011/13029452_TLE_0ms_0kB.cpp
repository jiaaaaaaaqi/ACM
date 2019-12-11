#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mod 1000000007

using namespace std;

long long int dp[2005];
long long int cnt[2005];
long long int maps[2005][2005];

void init() {
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	memset(maps, 0, sizeof(maps));
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
					maps[i][j]=1;
					cnt[j]++;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			dp[i]=cnt[i];
		}
		for(int k=2; k<m; k++) {
			for(int i=n; i>1; i--) {
				long long int ans=0;
				for(int j=1; j<=i; j++) {
					if(i%j == 0){
						ans += dp[j];
						ans %= mod;						
					}
				}
				dp[i]=max(dp[i], ans);
			}
		}
		long long int ans=0;
		for(int i=1; i<=n; i++) {
			ans += dp[i];
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}