#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

long long int mod = 1000000007;

ll fast_mul(ll a, ll b) {
	return (a*b%mod + mod) % mod;
}

void mat_mul(ll a[2][2], ll b[2][2]) {
	ll ans[2][2] = {0};
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans[i][j] += fast_mul(a[i][k], b[k][j]);
				ans[i][j] %= mod;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}

void mat_pow(ll a[2][2], ll b) {
	ll ans[2][2] = {0};
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			ans[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			mat_mul(ans, a);
		mat_mul(a, a);
		b >>= 1;
	}
	memcpy(a, ans, sizeof(ans));
}

int main() {
	ll a, b;
	while(scanf("%lld%lld",&a, &b) != EOF) {
		ll mat[2][2];
		mat[0][0] = 1;
		mat[0][1] = -1;
		mat[1][0] = 1;
		mat[1][1] = 0;
		ll n;
		scanf("%lld", &n);
		if(n == 1)
			printf("%lld\n", (a+mod) % mod);
		else if(n == 2)
			printf("%lld\n", (b+mod) % mod);
		else {
			n -= 2;
			mat_pow(mat, n);
			ll ans = (fast_mul(mat[0][0], b)+fast_mul(mat[0][1], a)) % mod;
			printf("%lld\n", (ans+mod) % mod);
		}
		memset(mat, 0, sizeof(mat));
	}
	return 0;
}
