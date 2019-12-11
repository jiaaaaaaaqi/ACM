#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

int p, q;
const int maxn = 2;

struct matrix {
	int mat[maxn][maxn];
};

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, int b) {
	matrix ans;
	matrix a = A;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(b) {
		if(b&1)
			ans = matmul(ans, a);
		a = matmul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	while(scanf("%lld%lld", &p, &q), p||q) {
		ll n;
		scanf("%lld", &n);
		if(n == 1) {
			printf("%lld\n", p);
		} else if(n == 2) {
			printf("%lld\n", p * p - 2 * q);
		} else {
			matrix res;
			matrix A;
			A.mat[0][0] = p;
			A.mat[0][1] = -q;
			A.mat[1][0] = 1;
			A.mat[1][1] = 0;
			res = matpow(A, n-2);
			ll ans = res.mat[0][0] * (p*p-2*q) + res.mat[0][1] * (p);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
