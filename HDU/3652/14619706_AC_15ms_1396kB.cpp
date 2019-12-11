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
const int mod = 2520;
using namespace std;

ll n, m, tol;
int k;
int digit[20];
ll dp[20][20][5];

void init() {
    memset(dp, -1, sizeof dp);
}

ll dfs(int pos, int x, int state, bool limit) {
    if(pos == 0)	return (state == 2 && x == 0) ? 1 : 0;
    if(!limit && dp[pos][x][state] != -1)	return dp[pos][x][state];
    int up = limit ? digit[pos] : 9;
    ll ans = 0;
    for(int i=0; i<=up; i++) {
        if(state == 0 && i == 1)
            ans += dfs(pos-1, (x*10+i)%13, 1, limit && i == digit[pos]);
        else if(state == 0 && i != 1)
            ans += dfs(pos-1, (x*10+i)%13, 0, limit && i == digit[pos]);
        else if(state == 1 && i == 3)
            ans += dfs(pos-1, (x*10+i)%13, 2, limit && i == digit[pos]);
        else if(state == 1 && i == 1)
            ans += dfs(pos-1, (x*10+i)%13, 1, limit && i == digit[pos]);
		else if(state == 1 && i != 1)
            ans += dfs(pos-1, (x*10+i)%13, 0, limit && i == digit[pos]);
		else
			ans += dfs(pos-1, (x*10+i)%13, 2, limit && i == digit[pos]);
    }
    if(!limit)	dp[pos][x][state] = ans;
    return ans;
}

ll solve(ll x) {
    int pos = 1;
    while(x) {
        digit[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, 0, 0, true);
}

int main() {
	init();
	while(~scanf("%lld", &n)) {
        ll ans = solve(n);
        printf("%lld\n", ans);
    }
    return 0;
}
