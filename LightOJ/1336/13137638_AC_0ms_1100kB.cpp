#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int n;
		scanf("%lld", &n);
		long long int ans = n;
		ans -= (long int)sqrt(n);
		ans -= (long int)sqrt(n/2);
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}