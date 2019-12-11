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
				ans.mat[i][j] = (ans.mat[i][j] % mod + mod) % mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, ll b) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<2; i++) {
		ans.mat[i][i] = 1;
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
	int cas = 1;
	while(scanf("%lld%lld", &n, &mod), n||mod) {
		n++;
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		A.mat[0][0] = A.mat[0][1] = A.mat[1][0] = 1;
		A.mat[1][1] = 0;
		if(n == 1) {
			ll ans = 1;
			ans %= mod;
			printf("Case %d: 0 %lld %lld\n", cas++, mod, ans);
			continue;
		} else if (n == 2) {
			ll ans = 1;
			ans %= mod;
			printf("Case %d: 1 %lld %lld\n", cas++, mod, ans);
			continue;
		} else {
			A = matpow(A, n-2);
			ll ans = A.mat[0][0] + A.mat[0][1];
			ans = 2 * ans - 1;
			ans %= mod;
			printf("Case %d: %lld %lld %lld\n", cas++, n-1, mod, ans);
		}
	}
	return 0;
}