#include<stdio.h>
#include<string.h>

int mod = 7;

void mat_mul(int a[2][2], int b[2][2]) {
	int ans[2][2];
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}

void mat_pow(int mat[2][2], int b) {
	int ans[2][2];
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			ans[i][j] = (i == j);
	while(b) {
		if(b & 1)
			mat_mul(ans, mat);
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main() {
	int a, b, n;
	while(scanf("%d%d%d", &a, &b, &n), a||b||n) {
		if(n == 1 && n == 2)
			printf("1\n");
		else {
			int ans[2][2];
			ans[0][0] = a;
			ans[0][1] = b;
			ans[1][0] = 1;
			ans[1][1] = 0;
			mat_pow(ans, n-2);
			printf("%d\n", (ans[0][0] + ans[0][1]) % mod);
		}
	}
	return 0;
}