#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int mod;

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
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			ans[i][j] = (i == j);
		}
	}
	while(b) {
		if(b & 1)
			mat_mul(ans, mat);
		mat_mul(mat, mat);
		b >>= 1;
	}
	memcpy(mat, ans, sizeof(ans));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, n, d;
		int ans[2][2];
		scanf("%d%d%d%d", &a, &b, &n, &d);
		if(a == 0 && b == 0) {
			printf("0\n");
			continue;
		}
		if(d == 1)
			mod = 10;
		else if(d == 2)
			mod = 100;
		else if(d == 3)
			mod = 1000;
		else if(d == 4)
			mod = 10000;
		if(n == 1) {
			printf("%d\n", a%mod);
		} else if(n == 2) {
			printf("%d\n", b%mod);
		} else {
			bool flag = false;
			if(a == 0) {
				n--;
				a = b;
				flag = true;
			} else if(b == 0) {
				n--;
				b = a;
				flag = true;
			}
			ans[0][0] = a;
			ans[0][1] = b;
			ans[1][0] = 1;
			ans[1][1] = 0;
			if(!flag)
				mat_pow(ans, n-2);
			else
				mat_pow(ans, n-1);
			int res = (ans[0][0]*a + ans[0][1]*b) % mod;
			printf("%d\n", res);
		}
	}
	return 0;
}