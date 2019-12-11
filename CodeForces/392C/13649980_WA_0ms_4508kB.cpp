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

const int maxn = 50;
ll m;
ll mod = 1000000007 ;

ll c[maxn][maxn];

struct matrix {
	ll mat[maxn * 2][maxn * 2];
};

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<m; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<m; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, ll b) {
	matrix ans;
	matrix p = A;
	for(int i=0; i<m; i++) {
		for(int j=0; j<m; j++) {
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

void handle() {
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	for(int i = 2; i <= 40; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i ) {
				c[i][j] = 1;
			} else {
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
	}
}

int main () {
	handle();
	ll n, k;
	while(scanf("%lld%lld", &n, &k)!= EOF) {
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		m = k * 2 + 3;
		for(int j=0; j<=k; j++) {
			A.mat[0][j + 1] = c[k][j];
			A.mat[0][j + k + 2] = c[k][j];
		}
		for(int i=1; i<=k; i++) {
			for(int j=0; j<=i; j++) {
				A.mat[i + 1][j + 1] = c[i][j];
				A.mat[i + 1][j + k + 2] = c[i][j];
			}
		}
		for(int i=1; i<=k; i++) {
			for(int j=0; j<=i; j++) {
				A.mat[i + k + 2][j + 1] = c[i][j];
			}
		}
		A = matpow(A, n-1);
		ll ans = 0;
		for(int i=0; i<m; i++) {
			ans = (ans + A.mat[0][i] % mod) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}