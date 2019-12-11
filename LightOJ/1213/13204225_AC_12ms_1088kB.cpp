#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

long long int mod;

long long int fast_mul(long long int a, long long int b) {
	long long int ans = 0;
	while(b) {
		if(b&1)
			ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

long long int fast_pow(long long int a, long long int b) {
	long long int ans = 1;
	while(b) {
		if(b&1)
			ans = fast_mul(ans, a);
		a = fast_mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int a, b;
		scanf("%lld%lld%lld", &a, &b, &mod);
		long long int sum = 0;
		for(int i=0; i<a; i++) {
			long long int num;
			scanf("%lld", &num);
			sum += num;
			sum %= mod;
		}
		long long int ans = fast_pow(a, b-1);
		ans = fast_mul(ans, b);
		ans = fast_mul(ans, sum);
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}