#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

const int maxn = 35;
ll n, k, mod;

struct matrix {
	ll mat[maxn][maxn];
};

matrix mat_add(matrix A, matrix B) {
	matrix ans;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans.mat[i][j] = A.mat[i][j] + B.mat[i][j];
			ans.mat[i][j] %= mod;
		}
	}
	return ans;
}

matrix mat_mul(matrix A, matrix B) {
	matrix ans;
	for(int i=0; i<n; i++) {
		ans.mat[i][i] = 0;
	}
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

matrix mat_pow(matrix A, int b) {
	matrix ans;
	matrix p = A;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			ans = mat_mul(ans, p);
		p = mat_mul(p, p);
		b >>= 1;
	}
	return ans;
}

matrix sum(matrix A, int m) {
	if(m == 1)
		return A;
	matrix t = sum(A, m/2);
	if(m & 1) {
		matrix cur = mat_pow(A, m/2+1);
		t = mat_add(t, mat_mul(t, cur));
		t = mat_add(t, cur);
	} else {
		matrix cur = mat_pow(A, m/2);
		t = mat_add(t, mat_mul(t, cur));
	}
	return t;
}

int main() {
	while(scanf("%lld%lld%lld", &n, &k, &mod) != EOF) {
		matrix A;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &A.mat[i][j]);
			}
		}
		matrix ans = sum(A, k);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%lld%c", ans.mat[i][j], j==n-1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}