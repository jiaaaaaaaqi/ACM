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
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				pre[i][j] += (a[i][k] * b[k][j]);
				pre[i][j] %= mod;
			}
		}
	}
	memcpy(a, pre, sizeof(pre));
}

void mat_pow(int mat[maxn][maxn], int b) {
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<n; i++) 
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
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
					res[i][j] += mat1[i][k] * mat2[k][j];
					res[i][j] %= mod;
				}
			}
		}
		mat_pow(res, n*n);
		long long int ans1 = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				ans1 += res[i][j];
			}
		}
		printf("%lld\n", ans1);
	}
	return 0;
}
