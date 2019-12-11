#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 505;
int n, m;
int num1[maxn];
int num2[maxn];
int dp[maxn][maxn];

void init() {
	memset(dp, 0, sizeof(dp));
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
}

int LICS() {
	for(int i=1; i<=n; i++) {
		int maxlen = 0;
		for(int j=1; j<=m; j++) {
			dp[i][j] = dp[i-1][j];
			if(num1[i] > num2[j]){
				maxlen = max(maxlen, dp[i-1][j]);
			}
			if(num1[i] == num2[j]){
				dp[i][j] = maxlen + 1;
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=m; i++)
		ans = max(ans, dp[n][i]);
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &num1[i]);
		scanf("%d", &m);
		for(int i=1; i<=m; i++)
			scanf("%d", &num2[i]);
		int ans = LICS();
		printf("%d\n", ans);
	}
	return 0;
} 