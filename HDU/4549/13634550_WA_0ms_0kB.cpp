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
ll mod = 1000000007;

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] %= (mod - 1);
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

ll fastmi(ll a, ll b) {
	int ans = 1;
	while(b) {
		if(b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	ll n;
	ll a, b;
	while(scanf("%lld%lld%lld", &a, &b, &n) != EOF) {
		n++;
		if(n == 1) {
			printf("%lld\n", a % mod);
		} else if(n == 2){
			printf("%lld\n", b % mod);
		} else {
			matrix A;
			A.mat[0][0] = 1;
			A.mat[0][1] = 1;
			A.mat[1][0] = 1;
			A.mat[1][1] = 0;
			A = matpow(A, n-3);
			ll powa = (A.mat[0][1] + A.mat[0][0]) % mod;
			ll powb = (A.mat[1][0] + A.mat[1][1]) % mod;
			ll ansa = fastmi(a, powa);
			ll ansb = fastmi(b, powb);
			ll ans = (ansa * ansb) % mod;
			printf("%lld\n", ans); 
		}
	}
	return 0;
}
