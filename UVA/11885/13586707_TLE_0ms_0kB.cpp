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

const int maxn = 2;

struct matrix {
	ll mat[maxn][maxn];
};
int n;
ll mod = 987654321;

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
	while(~scanf("%d", &n)) {
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		A.mat[0][0] = A.mat[0][1] = A.mat[1][0] = 1;
		if(n & 1) {
			printf("0\n");
			continue;
		} else {
			A = matpow(A, n-4);
			ll res = 0;
			res = A.mat[0][0];
			res %= mod;
			res -= (n/2 - 1);
			printf("%lld\n", (res + mod) % mod);
		}
	}
	return 0;
}
