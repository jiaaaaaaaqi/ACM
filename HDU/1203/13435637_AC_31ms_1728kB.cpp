#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n, m;
double vi[10005];
double dp[10005];
int wi[10005];

void init() {
	memset(wi, 0, sizeof(wi));
	memset(vi, 0, sizeof(vi));
	for(int i=0; i<10005; i++)
		dp[i] = 1.0;
}

double solve() {
	for(int i=1; i<=m; i++) {
		for(int j=n; j>=wi[i]; j--) {
			dp[j] = min(dp[j], dp[j - wi[i]] * (1 - vi[i]));
		}
	}
	return 1-dp[n];
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		for(int i=1; i<=m; i++)
			scanf("%d%lf", &wi[i], &vi[i]);
		double ans = solve();
		ans = ans * 100;
		printf("%.1lf%%\n", ans);
	}
	return 0;
}
