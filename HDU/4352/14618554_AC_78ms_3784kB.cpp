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
ll dp[20][1<<10][15];
int digit[20];

void init() {
    memset(dp, -1, sizeof dp);
}

int getnum(int x) {
    int ans = 0;
    while(x) {
        if(x & 1)	ans++;
        x >>= 1;
    }
    return ans;
}

int getstate(int pos, int state) {
    for(int i=pos; i<=9; i++) {
        if(state & (1 << i)) {
            return (state ^ (1 << i)) | (1 << pos);
        }
    }
    return state | (1 << pos);
}

ll dfs(int pos, int state, bool lead, bool limit) {
    if(pos == 0)	return getnum(state) == k ? 1 : 0;
    if(!limit && dp[pos][state][k] != -1)	return dp[pos][state][k];
    int up = limit ? digit[pos] : 9;
    ll ans = 0;
    for(int i=0; i<=up; i++) {
        if(lead) {
            if(i == 0)	ans += dfs(pos-1, 0, true, limit && i == digit[pos]);
            else	ans += dfs(pos-1, getstate(i, state), false, limit && i == digit[pos]);
        } else {
            ans += dfs(pos-1, getstate(i, state), false, limit && i == digit[pos]);
        }
    }
    if(!limit)	dp[pos][state][k] = ans;
    return ans;
}

ll solve(ll x) {
    int pos = 1;
    memset(digit, 0, sizeof digit);
    while(x) {
        digit[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos -1, 0, true, true);
}

int main() {
    int T;
    int cas = 1;
    scanf("%d", &T);
    init();
    while(T--) {
        scanf("%lld %lld %d", &n, &m, &k);
        ll ans = solve(m) - solve(n - 1);
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
