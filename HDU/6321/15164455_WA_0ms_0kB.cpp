#include<map>
#include<set>
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
const int maxn = 1<<10+5;
const int maxm = 10000007;
const int mod = 1e9+7;
using namespace std;

int n, m, tol, T;
int dp[maxn];
int cnt[maxn];
int ans[10];

void init() {
    memset(dp, 0, sizeof dp);
}

int calc(int x) {
    int ans = 0;
    while(x) {
        if(x & 1)	ans++;
        x >>= 1;
    }
    return ans;
}

void handle() {
    for(int i=1; i<=(1<<10); i++) {
        cnt[i] = calc(i);
    }
}

int main() {
    handle();
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        dp[0] = 1;
        char s[10];
        while(m--) {
            memset(ans, 0, sizeof ans);
            int u, v;
            scanf("%s%d%d", s, &u, &v);
            u--, v--;
            int y = (1<<u) + (1<<v);
            if(s[0] == '+') {
                for(int i=(1<<n)-1; i>=0; i--) {
                    if((i&(1<<u)) && (i&(1<<v))) {
                        dp[i] += dp[i-y];
                        dp[i] %= mod;
                    }
                }
            } else {
                for(int i=0; i<(1<<n); i++) {
                    if((i&(1<<u)) && (i&(1<<v))) {
                        dp[i] -= dp[i-y];
                        dp[i] %= mod;
                    }
                }
            }
            for(int i=1; i<(1<<n); i++)	ans[cnt[i]] += dp[i];
            for(int i=2; i<=n; i+=2)	printf("%d%c", ans[i], i==n ? '\n' : ' ');
        }
    }
    return 0;
}
