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
const int maxn = 5100;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int digit[10];
int dp[10][2];

void init() {
	memset(digit, 0, sizeof digit);
	memset(dp, -1, sizeof dp);
}

int dfs(int pos, int sta, bool limit) {
	if(pos == 0)	return 1;
	if(!limit && dp[pos][sta == 6] != -1)	return dp[pos][sta];
	int up = limit ? digit[pos] : 9;
	int tmp = 0;
	for(int i=0; i<=up; i++) {
		if(sta == 6 && i == 2)	continue;
		if(i == 4)	continue;
		tmp += dfs(pos -1 , i, limit && i == digit[i]);
	}
	if(!limit)	dp[pos][sta];
	return tmp;
}

int solve(int x) {
	int pos = 1;
	while(x) {
		digit[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos - 1, 0, true);
}

int main() {
    while(scanf("%d%d", &n, &m), n||m) {
		init();
		int ans = solve(m) - solve(n-1);
		printf("%d\n", ans);
    }
    return 0;
}
