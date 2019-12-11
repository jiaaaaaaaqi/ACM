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
struct Node {
    int first;
    ll second;
};
Node q[maxn];

void init() {
    memset(g, 0, sizeof g);
    memset(num, 0, sizeof num);
    memset(sum, 0, sizeof sum);
	for(int i=0; i<maxn; i++)	dp[1][i] = dp[0][i] = inf;
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
            for(int i=0; i<maxn; i++)	dp[flag][i] = inf;
            int head = 0;
            int tail = 0;
            int j = i * la;
            int k = max(0, j - lb);
            for( ; k<j-la; k++) {
                while(head < tail && q[tail-1].second >= dp[!flag][k] - sum[k] * g[i])	tail--;
                q[tail].first = k;
                q[tail++].second = dp[!flag][k] - sum[k] * g[i];
            }
            for( ; j<=min(i*lb, n); j++) {
                k = min(j-la, (i-1)*lb);
                while(head < tail && q[tail-1].second >= dp[!flag][k] - sum[k] * g[i])	tail--;
                q[tail].first = k;
            	q[tail++].second = dp[!flag][k] - sum[k] * g[i];
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
        if(ans != inf)	printf("%lld %lld %lld\n", ans, kl, lanum);
        else	printf("No solution.\n");
    }
    return 0;
}
