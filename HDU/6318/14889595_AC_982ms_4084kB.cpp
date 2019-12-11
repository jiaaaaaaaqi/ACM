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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 998244353;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
ll sum[maxn];
ll a[maxn];
ll b[maxn];

void init() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(sum, 0, sizeof sum);
}

void update(ll x) {
    for(int i=x; i<=n; i+=lowbit(i)) {
        sum[i]++;
    }
}

ll query(ll x) {
    ll ans = 0;
    for(int i=x; i>0; i-=lowbit(i)) {
        ans += sum[i];
    }
    return ans;
}

int main() {
    ll x, y;
    while(~scanf("%d%lld%lld", &n, &x, &y)) {
        init();
        for(int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }
        sort(b+1, b+1+n);
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ll s = lower_bound(b+1, b+1+n, a[i]) - b;
            ans += query(n) - query(s);
            update(s);
        }
        ans = ans * min(x, y);
        printf("%lld\n", ans);
    }    
    return 0;
}