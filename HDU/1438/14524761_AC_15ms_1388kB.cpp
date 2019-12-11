#include<map>
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
const int maxn = 200005;
const int maxm = 305;
using namespace std;

int n, m, tol;
ll dp[35][20][5][2];
int num[20];

void init() {
	memset(num, 0, sizeof num);
	memset(dp, 0, sizeof dp);
}

int main() {
	init();
	for(int i=0; i<16; i++) {
		for(int j=0; j<4; j++) {
			if(i & (1 << j)) {
				num[i]++;
			}
		}
	}
	dp[1][1][0][0] = 1;
	dp[1][2][1][0] = 1;
	dp[1][4][2][0] = 1;
	dp[1][8][3][0] = 1;
	for(int i=2; i<=31; i++) {
		for(int j=0; j<16; j++) {
			for(int k=0; k<4; k++) {
				for(int z=0; z<4; z++) {
					int cur = j | (1 << z);
					dp[i][cur][z][1] += dp[i - 1][j][k][1];
					if(abs(k - z) == 3) {
						dp[i][cur][z][1] += dp[i - 1][j][k][0];
					} else {
						dp[i][cur][z][0] += dp[i - 1][j][k][0];
					}
				}
			}
		}
	}
	for(int i=2; i<=31; i++) {
		ll ans = 0;
		for(int j=0; j<16; j++) {
			if(num[j] >= 3) {
				for(int k=0; k<4; k++) {
					ans += dp[i][j][k][1];
				}
			}
		}
		printf("N=%d: %lld\n", i, ans);
	}
	return 0;
}
