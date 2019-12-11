#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mod 1000000007

using namespace std;

int dp[2005];
int maps[2005][2005];
 
void init() {
	memset(dp, 0, sizeof(dp));
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
				}
			}
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				printf("%d ",maps[i][j]);
			puts("");
		}
		*/
		for(int k=1; k<m; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=i; j<=n; j++) {
					dp[j] = dp[j] + maps[i][j];
					dp[j] =dp[j] % mod;
				}
			}
		}
		long long int ans=0;
		for(int i=1; i<=n; i++) {
			ans=(ans+dp[i]) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}