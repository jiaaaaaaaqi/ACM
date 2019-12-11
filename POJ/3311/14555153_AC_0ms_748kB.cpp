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
const int maxn = 1030;
const int maxm = 1<<11;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int maps[15][15];
int dp[1<<11][15];

void init() {
	memset(maps, inf, sizeof maps);
	memset(dp, inf, sizeof dp);
}

void floyd() {
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
			}
		}
	}
}

int main() {
	while(scanf("%d", &n), n) {
		n++;
		init();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &maps[i][j]);
			}
		}
		floyd();
		dp[1][0] = 0;
		for(int i=1; i<(1<<n); i++) {
			for(int j=0; j<n; j++) {
				if(i & (1 << j)) {
					for(int k=0; k<n; k++) {
						int nex = i | (1 << k);
						dp[nex][k] = min(dp[nex][k], dp[i][j] + maps[j][k]);
					}
				}
			}
		}
		int x = (1 << n) - 1;
		int ans = inf;
		for(int i=1; i<n; i++) {
			ans = min(ans, dp[x][i] + maps[i][0]);
		}
		printf("%d\n", ans);
	}
    return 0;
}
