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

const int maxn = 6;

struct matrix {
	ll mat[maxn][maxn];
};
ll mod;

matrix matmul(matrix A, matrix B) {
	matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			for(int k=0; k<6; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] = (ans.mat[i][j] % mod + mod) % mod;
			}
		}
	}
	return ans;
}

matrix matpow(matrix A, ll b) {
	matrix ans;
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
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

int main() {
	ll n, sx, sy, dx, dy, t;
	while(~scanf("%lld%lld%lld%lld%lld%lld", &n, &sx, &sy, &dx, &dy, &t)) {
		if(t == 0) {
			printf("%lld %lld\n", sx, sy);
			continue;
		}
		mod = n;
		matrix A;
		memset(A.mat, 0, sizeof(A.mat));
		ll ans[6];
		ans[0] = sx - 1;
		ans[1] = sy - 1;
		ans[2] = (dx % mod + mod) % mod;
		ans[3] = (dy % mod + mod) % mod;
		ans[4] = 0;
		ans[5] = 1;
		A.mat[0][0] = 2;
		A.mat[0][1] = 1;
		A.mat[0][2] = 1;
		A.mat[0][4] = 1;
		A.mat[0][5] = 2; 
		A.mat[1][0] = 1;
		A.mat[1][1] = 2;
		A.mat[1][3] = 1;
		A.mat[1][4] = 1;
		A.mat[1][5] = 2;
		A.mat[2][0] = 1;
		A.mat[2][1] = 1;
		A.mat[2][2] = 1;
		A.mat[2][4] = 1;
		A.mat[2][5] = 2;
		A.mat[3][0] = 1;
		A.mat[3][1] = 1;
		A.mat[3][3] = 1;
		A.mat[3][4] = 1;
		A.mat[3][5] = 2;
		A.mat[4][4] = 1;
		A.mat[4][5] = 1;
		A.mat[5][5] = 1;
		/*
		for(int i=0; i<6; i++) {
			for(int j=0; j<6; j++) {
				printf("%lld%c", A.mat[i][j], j==5 ? '\n' : ' ');
			}
		}
		*/
		A = matpow(A, t);
		ll ansx = 0;
		ll ansy = 0;
		for(int i=0; i<6; i++) {
			ansx += (A.mat[0][i] * ans[i]);
			ansx %= mod;
			ansy += (A.mat[1][i] * ans[i]);
			ansy %= mod;
		}
		printf("%lld %lld\n", ansx + 1, ansy + 1);
	}
	return 0;
}