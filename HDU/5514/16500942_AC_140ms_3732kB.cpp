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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;
ll a[maxn];
ll vis[maxn];
ll num[maxn];

void init() {
    mes(a, 0);
    mes(vis, 0);
    mes(num, 0);
}

ll calc(ll x) {
    ll cnt = (m - 1) / x;
    return cnt * (cnt+1) / 2 * x;
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &n, &m);
        init();
        tol = 0;
        for(int i=1; i*i<=m; i++) {
            if(m % i == 0) {
                a[++tol] = i;
                if(i * i != m) {
                    a[++tol] = m / i;
                }
            }
        }
        sort(a+1, a+1+tol);
        ll b;
        for(int i=1; i<=n; i++) {
            scanf("%d", &b);
            b = __gcd(b, m);
            for(int i=1; i<=tol; i++) {
                if(a[i] % b == 0) {
                    vis[i] = 1;
                }
            }
        }
        ll ans = 0;
        for(int i=1; i<=tol; i++) {
            if(vis[i] != num[i]) {
                ans += calc(a[i]) * (vis[i] - num[i]);
                for(int j=i+1; j<=tol; j++) {
                    if(a[j] % a[i] == 0) {
                        num[j] += (vis[i] - num[i]);
                    }
                }
            }
        }
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}