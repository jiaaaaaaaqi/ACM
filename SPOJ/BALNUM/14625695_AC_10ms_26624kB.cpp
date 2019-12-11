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
ll dp[25][60000];
int digit[25];

void init() {
    memset(dp, -1, sizeof dp);
}
bool judge(int state) {
	int num[10];
	for(int i=0; i<10; i++) {
		num[i] = state % 3;
		state /= 3;
	}
	for(int i=0; i<10; i++) {
		if(num[i] == 0)	continue;
		if(i % 2 == 0 && num[i] == 2)	return false;
		if(i % 2 == 1 && num[i] == 1)	return false;
	}
	return true;
}

int getstate(int x, int state) {
    int num[10];
    for(int i=0; i<10; i++) {
        num[i] = state % 3;
        state /= 3;
    }
    if(num[x] == 0)	num[x] = 1;
    else if(num[x] == 1)	num[x] = 2;
    else	num[x] = 1;
    int ans = 0;
    for(int i=9; i>=0; i--) {
        ans = ans * 3 + num[i];
    }
    return ans;
}

ll dfs(int pos, int state, bool lead, bool limit) {
    if(pos == 0)	return judge(state) ? 1 : 0;
    if(!limit && !lead && dp[pos][state] != -1)	return dp[pos][state];
    int up = limit ? digit[pos] : 9;
    ll ans = 0;
    for(int i=0; i<=up; i++) {
        if(lead && i == 0)	ans += dfs(pos-1, 0, true, limit && i == digit[pos]);
        else ans += dfs(pos-1, getstate(i, state), false, limit && i == digit[pos]);
    }
    if(!lead && !limit)	dp[pos][state] = ans;
    return ans;
}

ll solve(ll x) {
    memset(digit, 0, sizeof digit);
    int pos = 1;
    while(x) {
        digit[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, 0, true, true);
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &n, &m);
        ll ans = solve(m) - solve(n-1);
        printf("%lld\n", ans);
    }
    return 0;
}
