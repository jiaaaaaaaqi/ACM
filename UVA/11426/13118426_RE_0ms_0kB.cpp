#include<stdio.h>
#include<string.h>
#include<algorithm>

long long int pre[4000001][4000001];

long long int gcd(long long int a, long long int b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

void handle() {
	memset(pre, 0, sizeof(pre));
	for(int i=1; i<4000001; i++) {
		for(int j=i+1; j<4000001; j++) {
			pre[i][j] = gcd(i, j);
		}
	}
}

int main() {
	handle();
	int n;
	while(scanf("%d", &n), n) {
		long long int ans=0;
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans += pre[i][j];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}