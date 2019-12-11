#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mod 10000007

typedef long long int ll;
using namespace std;

int n, m;

void init(ll ans[13][13], int n) {
	ll mat[13][13];
	memset(mat, 0, sizeof(mat));
	for(int i=0; i<n; i++) {
		mat[i][0] = 10;
		mat[i][n] = 1;
	}
	mat[n][n] = 1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<=i; j++) {
			mat[i][j] = 1;
		}
	}
	memcpy(ans, mat, sizeof(mat));
}

ll fast_mul(ll a, ll b)
{
	ll ans=0;
	while(b)
	{
		if(b%2)
			ans=(ans+a)%mod;
		a=(a+a)%mod;
		b/=2;
	}
	return ans;
}

void mat_mul(ll a[13][13], ll b[13][13]) {
	ll ans[13][13];
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				ans[i][j] += fast_mul(a[i][k], b[k][j]);
				ans[i][j] %= mod;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}

void mat_pow(ll mat[13][13], ll b) {
	ll ans[13][13];
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<13; i++) {
		for(int j=0; j<13; j++){
			ans[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1) 
			mat_mul(ans, mat);
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main () {
	ll a[13];
	ll mat[13][13];
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(a, 0, sizeof(a));
		a[0] = 23;
		for(int i=1; i<=n; i++) {
			ll x;
			scanf("%lld", &x);
			a[i] = x % mod;
		}
		a[0] = 23;
		a[n+1] = 3;
		if(m == 0) {
			printf("%lld\n", a[n] % mod);
		} else {
			n += 2;
			init(mat, n-1);
			/*
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					printf("%lld  ", mat[i][j]);
				}
				printf("\n");
			}
			*/
			mat_pow(mat, m);
			ll ans = 0;
			ll pre;
			for(int i=0; i<n; i++) {
				pre = fast_mul(a[i], mat[n-2][i]);
				ans = (ans + pre) % mod;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}