#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

long long int mod = 1e9+7;

long long int fac[100010];
long long int inv[100010];

long long int fast_pow(long long int a, long long int b) {
	long long int ans=1;
	while(b) {
		if(b&1)
			ans = (ans*a) % mod;
		a = (a*a) % mod;
		b >>= 1;
	}
	return ans;
}

void handle() {
	fac[1] = 1;
	for(int i=2; i<1e5+5; i++) {
		fac[i] = (fac[i-1] * (i%mod)) % mod;
	}
	inv[0] = inv[1] = 1;
	for(int i=2; i<1e5+5; i++) {
		inv[i] = fast_pow(fac[i], mod-2);
	}
}

int main() {
	handle();
	int T;
	scanf("%d", &T);
	while(T--) {
		long long int n,m;
		scanf("%lld%lld",&n, &m);
		m = abs(m);
		if(n < m) {
			printf("0\n");
			continue;
		} else if(n == m) {
			long long int ans = fast_pow(fast_pow(4, n), mod-2);
			printf("%lld\n", ans);
			continue;
		} else {
			long long int ans = 0;
			for(int x=m; 2*x<=n+m; x++) {
				long long int sum;
				sum = fac[n]%mod * inv[x]%mod * inv[n-x]%mod;
				sum = sum * fac[n-x]%mod * inv[x-m]%mod * inv[n+m-2*x]%mod;
				sum = sum * fast_pow(fast_pow(2, 2*x+n-n), mod-2);
				ans += sum;
				if(ans >= mod)
					ans -= mod;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}