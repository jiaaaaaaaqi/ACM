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
const int maxn = 100005;
const int maxm = 100005;
const int mod = 1000000007;
using namespace std;

ll n, m, tol;
struct Node {
    int id;
    ll val;
};
Node q[maxn];
ll num[maxn];
ll dp[maxn];

void init() {
    memset(q, 0, sizeof q);
    memset(dp, inf, sizeof dp);
    memset(num, 0, sizeof num);
}

int main() {
    while(~scanf("%lld%lld", &n, &m)) {
        init();
        bool flag = true;
        for(int i=1; i<=n; i++)	{
            scanf("%lld", &num[i]);
            if(num[i] > m)	flag = false;
        }
        if(!flag) {
            printf("-1");
            continue;
        }
        ll sum = 0;
        int pos = 1;
        int head = 0, tail = 0;
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            sum += num[i];
            while(sum > m && head != tail && pos < i)
                sum -= num[pos++];
            while(head != tail && num[i] >= q[tail - 1].val)
                tail--;
            q[tail].id = i;
            q[tail++].val = num[i];
            while(head != tail && q[head].id < pos)
                head++;
            dp[i] = dp[pos - 1] + q[head].val;
            for(int j=head; j<tail; j++) {
                dp[i] = min(dp[i], dp[q[j].id] + q[j + 1].val);
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
