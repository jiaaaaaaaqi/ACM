#include<map>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 2;

struct matrix {
	ll mat[maxn][maxn];
};
ll mod;

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, int b) {
	matrix ans;
	matrix p = A;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			ans = matmul(ans, p);
		p = matmul(p, p);
		b >>= 1;
	}
	return ans;
}

int main() {
	ll a, b, n;
	while(~scanf("%lld%lld%lld%lld", &a, &b, &n, &mod)) {
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		ll s1 = (2 * a) % mod;
		ll s2 = (2 * (a * a + b)) % mod;
		if(n == 1) {
			printf("%lld\n", s1);
			continue;
		} else if(n == 2) {
			printf("%lld\n", s2);
			continue;
		} else {
			A.mat[0][0] = 2 * a;
			A.mat[0][1] = b - a * a;
			A.mat[1][0] = 1;
			A.mat[1][1] = 0;
			A = matpow(A, n-2);
			ll ans = A.mat[0][0] * s2  + A.mat[0][1] * s1 ;
			printf("%lld\n", (ans % mod + mod) % mod);
		}
	}
	return 0;
}
