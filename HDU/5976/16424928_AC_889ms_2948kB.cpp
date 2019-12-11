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

int n, m;
int cas, tol, T;
ll f[maxn];
ll inv[maxn];

void handle() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}

int main() {
    handle();
    f[1] = 1;
    for (int i = 2; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        if (n == 1) {
            printf("1\n");
            continue;
        }
        ll l = 1, r = 3000000000;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll sum = (mid * mid + 3 * mid) / 2;
            if (sum >= n) r = mid;
            else l = mid + 1;
        }
        // printf("l = %lld\n", l);
        ll ans;
        ll tmp = n - ((l - 1) * (l - 1) + 3 * (l - 1)) / 2;
        if (tmp == l + 1) {
            l++;
            tmp = 0;
        }
        ans = f[l];
        if (tmp != 0) {
            ll chu = max(l - tmp + 1, 2ll);
            ans = ans * inv[chu] % mod;
            ans = ans * (chu + tmp) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
