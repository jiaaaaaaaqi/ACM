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
const int maxn = 1005;
const int maxm = 1100;
const int mod = 200;
using namespace std;

int n, m, tol;
int num[maxn];
int dp[maxn][maxm];

int getstate(int p, int state) {
	if(n - p <= 10)	return state>>1;
	else	return 1 << 9 | state >> 1;
}

int dfs(int pos, int state) {
	if(pos == n) {
		if(state == 0)	return 1;
		else	return 0;
	}
	if(dp[pos][state] != -1)	return dp[pos][state];
	dp[pos][state] = 0;
	if((state & 1) == 0)	dp[pos][state] = dfs(pos + 1, getstate(pos, state));
	else {
		int cnt = 0;
		for(int i=1; i<10 && cnt < 5; i++) {
			if(1 << i & state) {
				cnt++;
				if(num[pos + i] != num[pos])	continue;
				int newstate = state & ~1 & ~(1 << i);
				if(dfs(pos+1, getstate(pos, newstate))) {
					dp[pos][state] = 1;
					break;
				}
			}
		}
	}
	return dp[pos][state];
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i=n; i>=1; i--)	scanf("%d", num[i]);
		memset(dp, -1, sizeof dp);
		int ans = dfs(0, (1<<min(10, n)) - 1);
		printf("%d\n", ans);
	}
	return 0;
}
