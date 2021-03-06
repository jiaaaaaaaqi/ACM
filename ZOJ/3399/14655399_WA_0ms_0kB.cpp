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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10010;
const int maxm = 40000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
ll num[maxn];
ll sum[maxn];
ll g[205];
ll dp[2][maxn];
struct Node {
    int first;
    ll second;
};
Node q[maxn];

void init() {
    memset(g, 0, sizeof g);
    memset(num, 0, sizeof num);
    memset(sum, 0, sizeof sum);
    memset(dp, inf, sizeof dp);
}

int main() {
    int la, lb;
    while(~scanf("%d%d%d%d", &n, &m, &la, &lb)) {
        init();
        ll all = 0;
        for(int i=1; i<=n; i++)	{
            scanf("%lld", &num[i]);
            all += num[i];
        }
        for(int i=1; i<=m; i++)	scanf("%lld", &g[i]);
        ll l = all / n;
        sum[0] = 0;
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + (num[i] - l) * (num[i] - l);
        dp[0][0] = 0;
        bool flag = 1;
        ll ans = inf;
        ll kl;
        ll lanum;
        for(int i=1; i<=m; i++) {
            memset(dp[flag], inf, sizeof dp[flag]);
            int head = 0;
            int tail = 0;
            for(int j=i*la; j<=min(i*lb, n); j++) {
                while(head < tail && q[tail-1].second >= dp[!flag][j-la] - sum[j-la] * g[i])	tail--;
                q[tail].first = j - la;
                q[tail++].second = dp[!flag][j-la] - sum[j-la] * g[i];
                while(head < tail && q[head].first + lb < j)	head++;
                dp[flag][j] = q[head].second + sum[j] * g[i];
            }
            if(ans > dp[flag][n]) {
                ans = dp[flag][n];
                kl = i;
                lanum = n - q[head].first;
            }
            flag = !flag;
        }
        if(ans > inf)	printf("%lld %lld %lld\n", ans, kl, lanum);
        else	printf("No solution.\n");
    }
    return 0;
}
