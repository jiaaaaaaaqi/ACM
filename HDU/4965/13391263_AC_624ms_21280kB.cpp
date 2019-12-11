#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=1005;
int mod = 6;
int n, m;
int mat1[maxn][maxn];
int mat2[maxn][maxn];
int ans[maxn][maxn];
int pre[maxn][maxn];
int res[maxn][maxn];

void init() {
	memset(mat1, 0, sizeof(mat1));
	memset(mat2, 0, sizeof(mat2));
	memset(res, 0, sizeof(res));
}

void mat_mul(int a[maxn][maxn], int b[maxn][maxn]) {
	memset(pre, 0, sizeof(pre));
	for(int i=0; i<m; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<m; k++) {
				pre[i][j] += (a[i][k] * b[k][j]);
				pre[i][j] %= mod;
			}
		}
	}
	memcpy(a, pre, sizeof(pre));
}

void mat_pow(int mat[maxn][maxn], int b) {
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<m; i++) 
		ans[i][i] = 1;
	while(b) {
		if(b & 1)
			mat_mul(ans, mat);
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &mat1[i][j]);
			}
		}
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &mat2[i][j]);
			}
		}
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++) {
				for(int k=0; k<n; k++) {
					res[i][j] += mat2[i][k] * mat1[k][j];
					res[i][j] %= mod;
				}
			}
		}
		/*
		for(int i=0; i<m; i++) {
			for(int j=0; j<m; j++) {
				printf("%d ",res[i][j]);
			}
			printf("\n");
		}
		*/
		mat_pow(res, n*n-1);
		memset(ans, 0, sizeof(ans));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				for(int k=0; k<m; k++) {
					ans[i][j] += mat1[i][k] * res[k][j];
					ans[i][j] %= mod;
				}
			}
		}
		memcpy(res, ans, sizeof(ans));
		memset(ans, 0, sizeof(ans));
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				for(int k=0; k<m; k++) {
					ans[i][j] += (res[i][k] * mat2[k][j]);
					ans[i][j] %= mod;
				}
			}
		}
		long long int ans1 = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				ans1 += ans[i][j];
			}
		}
		printf("%lld\n", ans1);

	}
	return 0;
}
