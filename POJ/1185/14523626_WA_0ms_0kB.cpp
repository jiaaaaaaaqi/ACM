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
const int maxn = 100;
const int maxm = 1 << 10;
const int mod = 200;
using namespace std;

int n, m, tol;
int dp[maxn][maxn][maxn];
int cur[maxn];
int soid[maxm];
int state[maxn];

void init() {
	tol = 0;
	memset(dp, 0, sizeof dp);
	memset(soid, 0, sizeof soid);
	memset(cur, 0, sizeof cur);
	for(int i=0; i<(1<<m); i++) {
		if(i & (i << 1))
			continue;
		if(i & (i << 2))
			continue;
		else {
			state[++tol] = i;
			int num = i;
			int ans = 0;
			while(num) {
				if(num & 1)	ans++;
				num >>= 1;
			}
			soid[tol] = ans;
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		char str[15];
		for(int i=1; i<=n; i++) {
			scanf("%s", str+1);
			for(int j=1; j<=m; j++) {
				char x = str[j];
				if(x == 'H')
					cur[i] |= (1 << (m - j));
			}
		}
		for(int i=1; i<=tol; i++) {
			if(state[i] & cur[1])
				continue;
			else
				dp[1][i][0] = soid[i];
		}
		for(int i=1; i<=tol; i++) {
			if(state[i] & cur[2])	continue;
			for(int j=1; j<=tol; j++) {
				if(state[j] & cur[1])	continue;
				if(state[j] & state[i])	continue;
				dp[2][i][j] = max(dp[2][i][j], dp[1][j][0] + soid[i]);
			}
		}
		for(int i=2; i<=tol; i++) {
			for(int j=1; j<=tol; j++) {
				if(state[j] & cur[i])	continue;
				for(int k=1;  k<=tol; k++) {
					if(state[k] & cur[i-1])	continue;
					if(state[k] & state[j])	continue;
					for(int z=1; z<=tol; z++) {
						if(state[z] & cur[i-2])	continue;
						if(state[z] & state[j])	continue;
						if(state[z] & state[k])	continue;
						dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][z] + soid[j]);
					}
				}
			}
		}
		int ans = 0;
		for(int i=1; i<=tol; i++) {
			if(state[i] & cur[n])	continue;
			for(int j=1; j<=tol; j++) {
				if(state[j] & cur[n-1])	continue;
				if(state[j] & state[i])	continue;
				ans = max(ans, dp[n][i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
