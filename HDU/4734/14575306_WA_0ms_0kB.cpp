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
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int num;
int digit[15];
int dp[15][maxn];

void init() {
    memset(digit, 0, sizeof digit);
}

int F(int x) {
    if(x == 0)	return 0;
    int ans = F(x / 10);
    return (ans << 1) + x % 10;
}

int dfs(int pos, int sum, int limit) {
    if(pos == 0)	return sum <= num ? 1 : 0;
    if(sum > num)	return 0;
    if(!limit && dp[pos][num - sum] != -1)	return dp[pos][num - sum];
    int up = limit ? digit[pos] : 9;
    int ans = 0;
    for(int i=0; i<=up; i++) {
        ans += dfs(pos - 1, sum + i * (1 << (pos - 1)), limit && i == digit[pos]);
    }
    if(!limit)	dp[pos][num - sum] = ans;
    return ans;
}

int solve(int x) {
    int pos = 1;
    while(x) {
        digit[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos -1, 0, true);
}

int main() {
    int T;
    int cas = 1;
    scanf("%d", &T);
    memset(dp, -1, sizeof dp);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        num = F(n);
        int ans = solve(m);
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
