#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

ll mod;

void mat_mul(ll a[3][3], ll b[3][3]) {
	ll ans[3][3];
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}

void mat_pow(ll mat[3][3], ll b) {
	ll ans[3][3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			ans[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1) {
			mat_mul(ans, mat);
		}
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main() {
	ll n;
	while(scanf("%lld%lld", &n, &mod) != EOF) {
		if(n == 1) {
			printf("%d\n", 1%mod);
			continue;
		}
		if(n == 2) {
			printf("%d\n", 2%mod);
			continue;
		}
		ll ans[3][3];
		ans[0][0] = 1;
		ans[0][1] = 2;
		ans[0][2] = 1;
		ans[1][0] = 1;
		ans[1][1] = 0;
		ans[1][2] = 0;
		ans[2][0] = 0;
		ans[2][1] = 0;
		ans[2][2] = 1;
		mat_pow(ans, n-2);
/*
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
*/
		ll res;
		res = (2*ans[0][0] + ans[0][1] + ans[0][2]) % mod;
		printf("%lld\n", res);
	}
	return 0;
}