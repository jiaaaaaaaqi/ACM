#include<stdio.h>
int main() {
	long long  n;
	while(scanf("%lld", &n) != EOF) {
		long long  ans = (n + 1) * n / 2;
		printf("%lld\n", ans);
	}
	return 0;
}