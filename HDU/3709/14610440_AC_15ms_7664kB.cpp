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
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

ll n, m, tol;
int digit[20];
ll dp[20][20][2000];

void init() {
	memset(dp, -1, sizeof dp);
}

ll dfs(int pos, int mid, ll state, bool limit) {
	if(pos == 0)	return state == 0 ? 1 : 0;
	if(state < 0)	return 0;
	if(!limit && dp[pos][mid][state] != -1)	return dp[pos][mid][state];
	int up = limit ? digit[pos] : 9;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		ans += dfs(pos - 1, mid, state + (pos - mid) * i, limit && i == digit[pos]);
	}
	if(!limit)	dp[pos][mid][state] = ans;
	return ans;
}

ll solve(ll x) {
	memset(digit, 0, sizeof digit);
	int pos = 1;
	while(x) {
		digit[pos++] = x % 10;
		x /= 10;
	}
	ll ans = 0;
	for(int i=1; i<pos; i++) {
		ans += dfs(pos-1, i, 0, true);
	}
	return ans - pos;
}

int main() {
    int T;
    cin >> T;
    init();
    while(T--) {
		scanf("%lld%lld", &n, &m);
		ll ans = solve(m) - solve(n-1);
		cout << ans << endl;
    }
    return 0;
}
