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

const int maxn = 5;

struct matrix {
	ll mat[maxn][maxn];
};
ll mod = 1000000007;

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			for(int k=0; k<5; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, ll b) {
	matrix ans;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			ans = matmul(ans, A);
		A = matmul(A, A);
		b >>= 1;
	}
	return ans;
}

int main() {
	ll n;
	while(~scanf("%lld", &n)) {
		ll a1, ax, ay;
		ll b1, bx, by;
		scanf("%lld%lld%lld", &a1, &ax, &ay);
		scanf("%lld%lld%lld", &b1, &bx, &by);
		if(n == 0) {
			printf("0\n");
			continue;
		} else if(n == 1) {
			ll ans = a1 * b1 % mod;
			printf("%lld\n", ans);
			continue;
		} else {
			ll res[maxn];
			res[0] = a1 * b1 % mod;
			res[1] = a1 * b1 % mod;
			res[2] = a1 % mod;
			res[3] = b1 % mod;
			res[4] = 1;
			matrix A;
			memset(A.mat, 0, sizeof(A.mat));
			A.mat[0][0] = 1;
			A.mat[0][1] = ax * bx % mod;
			A.mat[0][2] = ax * by % mod;
			A.mat[0][3] = ay * bx % mod;
			A.mat[0][4] = ay * by % mod;
			A.mat[1][1] = ax * bx % mod;
			A.mat[1][2] = ax * by % mod;
			A.mat[1][3] = ay * bx % mod;
			A.mat[1][4] = ay * by % mod;
			A.mat[2][2] = ax % mod;
			A.mat[2][4] = ay % mod;
			A.mat[3][3] = bx % mod;
			A.mat[3][4] = by % mod;
			A.mat[4][4] = 1;
			A = matpow(A, n-1);
			ll ans = 0;
			for(int i=0; i<5; i++) {
				ans += res[i] * A.mat[0][i];
				ans %= mod;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}