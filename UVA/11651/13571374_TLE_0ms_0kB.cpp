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

const int maxn = 155;
ll mod = 4294967296;

struct matrix {
	int mat[maxn][maxn];
};

ll dp[30][10];

matrix matmul(matrix a, matrix b, int n) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a.mat[i][j] == 0)
				continue;
			for(int k=0; k<n; k++) {
				ans.mat[i][k] += a.mat[i][j] * b.mat[j][k];
				ans.mat[i][k] %= mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix a, ll b, int n) {
	matrix ans;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			ans = matmul(ans, a, n);
		a = matmul(a, a, n);
		b >>= 1;
	}
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		int base, so;
		scanf("%d%d", &base, &so);
		int N = (base-1) * (base-1) * base;
		printf("Case %d: ", cas++);
		for(int i=1; i<base; i++)
			dp[0][i] = 1;
		for(int i=0; i<(base-1) * (base-1); i++) {
			for(int j=0; j<base; j++) {
				for(int k=0; k<base; k++) {
					if(k == j)
						continue;
					int d = (k-j) * (k-j);
					if(i+d < (base-1) * (base-1)) {
						dp[i+d][k] += dp[i][j];
					}
				}
			}
		}
		/*
		for(int i=0; i<base; i++) {
			for(int j=0; j<base; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
		*/
		if(so < (base-1) * (base-1)) {
			ll ans = 0;
			for(int i=0; i<base; i++) 
				ans += dp[so][i];
			printf("%lld\n", ans);
			continue;
		}
		matrix res;
		memset(res.mat, 0, sizeof(res.mat));
		for(int i=0; i<(base-1) * (base-1); i++) {
			for(int j=0; j<base; j++) {
				res.mat[i*base + j][0] = dp[i][j];
			}
		}
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		for(int i=base; i<N; i++) {
			A.mat[i-base][i] = 1;
		}
		for(int i=0; i<base; i++) {
			for(int j=0; j<base; j++) {
				int d = (j-i) * (j-i);
				A.mat[N - base + i][base*((base-1) * (base-1) - d) + j] = 1;
			}
		}
		/*
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				printf("%d ", A.mat[i][j]);
			}
			printf("\n");
		}
		*/
		A = matpow(A, so-(base-1)*(base-1)+1, N);
		ll ans = 0;
		for(int i=N-base; i<N; i++) {
			for(int j=0; j<N; j++) {
				ans += A.mat[i][j] * res.mat[j][0];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

