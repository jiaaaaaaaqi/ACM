#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;
ll ans;
ll a[maxn];

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

ll calc(ll x) {
    ll cnt = (m - 1) / x;
    return cnt * (cnt+1) / 2 * x;
}

void dfs(ll res, int id, int flag) {
    if (res >= m) return ;
    if (flag)    ans += calc(res);
    else        ans -= calc(res);
    for (int i = id + 1; i <= n; i++) {
        dfs(lcm(res, a[i]), i, !flag);
    }
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] = __gcd(a[i], m);
        }
        sort(a+1, a+1+n);
        n = unique(a+1, a+1+n) - (a+1);
        // for (int i = 1; i <= n; i++)
        //     printf("%lld%c", a[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; i++) {
            dfs(a[i], i, 1);
        }
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}