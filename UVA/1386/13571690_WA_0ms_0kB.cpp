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

int n, mod, d, k;
const int maxn = 505;

struct matrix {
	int mat[maxn];
};

matrix matmul(matrix a, matrix b) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans.mat[i] += (a.mat[j] * b.mat[(i-j+n)%n]);
			ans.mat[i] %= mod;
		}
	}
	return ans;
}


int main() {
	while(scanf("%d%d%d%d", &n, &mod, &d, &k)!=EOF) {
		matrix ans;
		for(int i=0; i<n; i++) {
			scanf("%d", &ans.mat[i]);
		}
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		A.mat[0] = 1;
		for(int i=1; i<=d; i++) {
			A.mat[i] = A.mat[n-i] = 1;
		}
		while(k) {
			if(k & 1) {
				ans = matmul(ans, A);
			}
			A = matmul(A, A);
			k >>= 1;
		}
		for(int i=0; i<n; i++)
			printf("%d%c", ans.mat[i], i==n-1 ? '\n' : ' ');
	}
	return 0;
}