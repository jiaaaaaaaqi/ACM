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
const int maxn = 10010;
const int maxm = 40000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
ll num[maxn];
ll sum[maxn];
ll g[205];
ll dp[2][maxn];
deque< pair<int, ll > > q;

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
        ll ans = 0x3f3f3f3f3f3f3f3f;
		ll kl;
        ll lanum;
        for(int i=1; i<=m; i++) {
            memset(dp[flag], inf, sizeof dp[flag]);
            q.empty();
            int j = i * la;
            int k = max(0, j - lb);
            for( ; k<j-la; k++) {
                while(!q.empty() && q.back().second >= dp[!flag][k] - sum[k] * g[i])	q.pop_back();
                q.push_back(make_pair(k, dp[!flag][k] - sum[k] * g[i]));
            }
            for( ; j<=min(i*lb, n); j++) {
                k = min(j-la, (i-1)*lb);
                while(!q.empty() && q.back().second >= dp[!flag][k] - sum[k] * g[i])	q.pop_back();
                q.push_back(make_pair(k, dp[!flag][k] - sum[k] * g[i]));
                while(!q.empty() && q.front().first + lb < j)	q.pop_front();
                dp[flag][j] = q.front().second + sum[j] * g[i];
            }
            if(ans > dp[flag][n]) {
                ans = dp[flag][n];
                kl = i;
                lanum = n - q.front().first;
            }
            flag = !flag;
        }
        if(ans != 0x3f3f3f3f3f3f3f3f)	printf("%lld %lld %lld\n", ans, kl, lanum);
        else	printf("No solution.\n");
    }
    return 0;
}
