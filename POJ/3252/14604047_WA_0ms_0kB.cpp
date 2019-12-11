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
const int maxn = 10005;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

ll n, m, tol;
int num;
int digit[50];
int dp[50][100][100];

ll dfs(int pos, int num0, int num1, bool lead, bool limit) {
	if(pos == 0)	return num0 >= num1;
	if(!lead && !limit && dp[pos][num0][num1] != -1)	return dp[pos][num0][num1] ;
	int up = limit ? digit[pos] : 1;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		if(lead) {
			if(i)	ans += dfs(pos - 1, 0, 1, false, limit && i == digit[pos]);
			else	ans += dfs(pos - 1, num0, num1 + 1, true, limit && i == digit[pos]);
		} else {
			if(i)	ans += dfs(pos - 1, num0, num1 + 1, false, limit && i == digit[pos]);
			else	ans += dfs(pos - 1, num0 + 1, num1, false, limit && i == digit[pos]);
		}
	}
	if(!lead && !limit)	dp[pos][num0][num1] = ans;
	return ans;
}

ll solve(ll x) {
	memset(digit, 0, sizeof digit);
	int pos = 1;
	while(x) {
		digit[pos++] = x & 1;
		x >>= 1;
	}
	return dfs(pos - 1, 0, 0, true, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	while(~scanf("%lld%lld", &n, &m)) {
		ll ans = solve(m) - solve(n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
