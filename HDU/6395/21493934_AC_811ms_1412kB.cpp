#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1010;
const int maxm = 2010;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

struct Matrix {
	int n, m;
	ll mat[4][4];
};

Matrix mat_mul(Matrix a, Matrix b) {
	Matrix ans;
	ans.n = a.n;
	ans.m = b.m;
	memset(ans.mat, 0, sizeof ans.mat);
	for(int i=1; i<=a.n; i++) {
		for(int j=1; j<=b.m; j++) {
			for(int k=1; k<=b.n; k++) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

Matrix mat_pow(Matrix a, int b) {
	Matrix ans;
	ans.n = ans.m = 3;
	memset(ans.mat, 0, sizeof ans.mat);
	for(int i=1; i<=3; i++)	ans.mat[i][i] = 1;
	while(b) {
		if(b&1) {
			ans = mat_mul(ans, a);
		}
		a = mat_mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	cin >> T;
	int A, B, C, D, P;
	while(T--) {
		scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &P, &n);
		if(n == 1) {printf("%d\n", A); continue;}
		if(n == 2) {printf("%d\n", B); continue;}
		Matrix m1;
		Matrix m2;
		memset(m1.mat, 0, sizeof m1.mat);
		memset(m2.mat, 0, sizeof m2.mat);
		m1.n = m1.m = 3;
		m2.n = 3, m2.m = 1;
		m2.mat[1][1] = B;
		m2.mat[2][1] = A;
		m2.mat[3][1] = 1;
		int last;
		for(int i=3; i<=n; i++) {
			if((P/i) == 0)	last = n;
			else	last = min(n, P / (P/i));
			m1.mat[1][1] = D, m1.mat[1][2] = C, m1.mat[1][3] = P/i;
			m1.mat[2][1] = 1, m1.mat[2][2] = 0, m1.mat[2][3] = 0;
			m1.mat[3][1] = 0, m1.mat[3][2] = 0, m1.mat[3][3] = 1;
			m1 = mat_pow(m1, last-i+1);
			m2 = mat_mul(m1, m2);
//			for(int i=1; i<=m1.n; i++) {
//				for(int j=1; j<=m1.m; j++) {
//					printf("%d ", m1.mat[i][j]);
//				}
//				printf("\n");
//			}
			i = last;
		}
		printf("%I64d\n", m2.mat[1][1]);
	}
	return 0;
}