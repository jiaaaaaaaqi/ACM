#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 20;

struct matrix {
	ll mat[maxn][maxn];
};
int n, m, mod;

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
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
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
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
	while(scanf("%d%d%d", &n, &m, &mod), n||m||mod) {
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		for(int i=0; i<n; i++) {
			scanf("%lld", &A.mat[0][i]);
		}
		for(int i=1; i<n; i++) {
			A.mat[i][i-1] = 1;
		}
		matrix ans;
		for(int i=n-1; i>=0; i--)
			scanf("%lld", &ans.mat[i][0]);
		if(m <= n)
			printf("%lld\n", ans.mat[n-m][0] % mod);
		else {
			A = matpow(A, m - n);
			ll res = 0;
			for(int i=0; i<n; i++) {
				res += (ans.mat[i][0] * A.mat[0][i]);
				res %= mod;
			}
			printf("%lld\n", res);
		}
		
	}
	return 0;
}
