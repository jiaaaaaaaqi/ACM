#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int ans = (1 + n) * n / 2;
		printf("%d\n", ans);
	}
	return 0;
}