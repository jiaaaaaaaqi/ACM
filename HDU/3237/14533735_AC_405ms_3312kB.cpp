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
const int maxn = 105;
const int maxm = 1 << 8;
const int mod = 200;
using namespace std;

int n, m, tol;
int cnt[maxm];
int num[maxn];
int dp[2][maxn][maxm][10];

void handle() {
	for(int i=1; i<(1<<8); i++) {
		int tmp = i;
		int ans = 0;
		while(tmp) {
			ans += (tmp & 1);
			tmp >>= 1;
		}
		cnt[i] = ans;
	}
}

void init() {
	memset(num, 0, sizeof num);
}

int main() {
	handle();
	int cas = 1;
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		int mx = 0;
		int state = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &num[i]);
			num[i] -= 25;
			mx = max(mx, num[i]);
			state |= (1 << num[i]);
		}
		mx++;
		for(int j=0; j<=m; j++) {
			for(int k=0; k<(1<<mx); k++) {
				for(int s=0; s<=mx; s++) {
					dp[1][j][k][s] = inf;
				}
			}
		}
		dp[1][0][1<<num[1]][num[1]] = 1;
		dp[1][1][0][mx] = 0;
		int flag = 0;
		for(int i=2; i<=n; i++) {
			for(int j=0; j<=m; j++) {
				for(int k=0; k<(1<<mx); k++) {
					for(int s=0; s<=mx; s++) {
						dp[flag][j][k][s] = inf;
					}
				}
			}
			for(int j=0; j<=m&&j<i; j++) {
				for(int k=0; k<(1<<mx); k++) {
					for(int s=0; s<=mx; s++) {
						if(dp[!flag][j][k][s] == inf)	continue;
						int x = k | (1 << num[i]);
						if(j < m)
							dp[flag][j+1][k][s] = min(dp[flag][j+1][k][s], dp[!flag][j][k][s]);
						if(s != num[i])
							dp[flag][j][x][num[i]] = min(dp[flag][j][x][num[i]], dp[!flag][j][k][s] + 1);
						else
							dp[flag][j][x][s] = min(dp[flag][j][x][s], dp[!flag][j][k][s]);
					}
				}
			}
			flag = !flag;
		}
		flag = !flag;
		int ans = n;
		for(int j=0; j<=m; j++) {
			for(int k=0; k<(1<<mx); k++) {
				for(int s=0; s<mx; s++) {
					if(dp[flag][j][k][s] == inf)	continue;
					int x = k ^ state;
					ans = min(ans, cnt[x] + dp[flag][j][k][s]);
				}
			}
		}
		printf("Case %d: %d\n\n", cas++, ans);
	}
	return 0;
}
