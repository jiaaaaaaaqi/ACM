#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

int mod;

void mat_mul(int a[3][3], int b[3][3]) {
	int ans[3][3];
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}

void mat_pow(int mat[3][3], int b) {
	int ans[3][3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			ans[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1) {
			mat_mul(ans, mat);
		}
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main() {
	int n;
	while(scanf("%d%d", &n, &mod) != EOF) {
		if(n == 1) {
			printf("1\n");
			continue;
		}
		if(n == 2) {
			printf("2\n");
			continue;
		}
		int ans[3][3];
		ans[0][0] = 1;
		ans[0][1] = 2;
		ans[0][2] = 1;
		ans[1][0] = 1;
		ans[1][1] = 0;
		ans[1][2] = 0;
		ans[2][0] = 0;
		ans[2][1] = 0;
		ans[2][2] = 1;
		mat_pow(ans, n-2);
/*
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
*/
		ll res;
		res = (2*ans[0][0] + ans[0][1] + ans[0][2]) % mod;
		printf("%lld\n", res);
	}
	return 0;
}