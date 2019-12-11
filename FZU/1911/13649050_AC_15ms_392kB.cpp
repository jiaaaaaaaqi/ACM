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

const int maxn = 3;

struct matrix {
	int mat[maxn][maxn];
};
int mod;

int res[205][205];

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] = (ans.mat[i][j] % mod + mod) % mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, int b) {
	matrix ans;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
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

void solve(int n) {
	memset(res, 0, sizeof(res));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i-1; j++) {
			res[i][j] = 1;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=n-i; j<n; j++) {
			res[i][j] = -1;
		}
	}
	int flag = 1;
	for(int i=0; i<n; i++) {
		if(flag)
			res[i][n-i-1] = 1;
		else
			res[i][n-i-1] = 0;
		flag = 1 - flag;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d%c", res[i][j], j==n-1 ? '\n' : ' ');
		}
	}
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		mod = m;
		int r;
		if(n == 1) {
			r = 1 % mod;
		} else if (n == 2) {
			r = 2 % mod;
		} else {
			ll ans[maxn];
			ans[0] = 2;
			ans[1] = 1;
			ans[2] = 1;
			matrix A;
			memset(A.mat, 0, sizeof(A.mat));
			A.mat[0][0] = A.mat[0][1] = A.mat[0][2] = 1;
			A.mat[1][1] = A.mat[1][2] = A.mat[2][1] = 1;
/*
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					printf("%d%c", A.mat[i][j], j==2 ? '\n' : ' ');
				}
			}
*/
			A = matpow(A, n-2);
/*
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					printf("%d%c", A.mat[i][j], j==2 ? '\n' : ' ');
				}
			}
*/
			r = 0;
			for(int i=0; i<3; i++) {
				r += A.mat[0][i] * ans[i];
				r %= mod;
			}
		}
//		printf("r = %d\n", r); 
		if(r & 1 || r == 0) {
			printf("Case %d: No\n", cas++);
		} else {
			printf("Case %d: Yes\n", cas++);
			solve(r);
		}
	}
	return 0;
}