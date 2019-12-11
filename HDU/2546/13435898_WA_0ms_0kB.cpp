#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n, m;
int vi[1005];
int dp[1005];
int wi[1005];

void init() {
	memset(vi, 0, sizeof(vi));
	memset(wi, 0, sizeof(wi));
	memset(dp, 0, sizeof(dp));
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d", &vi[i]);
			wi[i] = vi[i];
		}
		sort(vi+1, vi+n+1);
		sort(wi+1, wi+n+1);
		int m;
		scanf("%d", &m);
		m -= 5;
		n--;
		for(int i=1; i<=n; i++) {
			for(int j=m; j>=wi[i]; j--) {
				dp[j] = max(dp[j], dp[j - wi[i]] + vi[i]);
			}
		}
		int ans = m - dp[m] + 5 - wi[n+1];
		printf("%d\n", ans);
	}
	return 0;
}