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

const int maxn = 55;

struct matrix {
	int mat[maxn][maxn];
}; 

ll n;
int mod = 1000;

matrix matmul(matrix a, matrix b) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix a, ll b) {
	matrix ans;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1) {
			ans = matmul(ans, a);
		}
		a = matmul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll b;
		scanf("%lld%lld", &n, &b);	
		matrix res;
		for(int i=0; i<n; i++) {
			ll x;
			scanf("%lld", &x);
			res.mat[i][0] = x % 1000;
		}
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		for(int i=0; i<n; i++) {
			int m;
			scanf("%d", &m);
			for(int j=0; j<m; j++) {
				int pos;
				scanf("%d", &pos);
				A.mat[i][pos] = 1;
			}
		}
		A = matpow(A, b);		
		matrix ans = matmul(A, res);
/*
		matrix ans;
		memset(ans.mat, 0, sizeof(ans.mat));
		for(int i=0; i<n; i++) {
			for(int j=0; j<1; j++) {
				for(int k=0; k<n; k++) {
					ans.mat[i][j] += A.mat[i][k] * res.mat[k][j];
					ans.mat[i][j] %= mod;
				}
			}
		}
*/
		for(int i=0; i<n; i++) {
			printf("%lld%c", ans.mat[i][0], i==n-1 ? '\n':' ');
		}
	}
	return 0;
}

