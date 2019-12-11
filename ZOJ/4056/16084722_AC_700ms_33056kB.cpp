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
#define  INOPEM     freopen("in.txt", "r", stdin)
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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scanf("%d", &T);
    ll a, b, c, d, v, t;
    while (T--) {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &v, &t);
        std::vector<ll> vec;
        ll mx = a * c / gcd(a, c);
        for (ll i = 0; i <= mx; i += a)
            vec.push_back(i);
        for (ll i = 0; i <= mx; i += c)
            vec.push_back(i);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int tmp = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] - vec[i - 1] > v)
                tmp++;
        }
        ll ans = t / a * b + t / c * d + b + d - 1;
        ll x = t / mx;
        ans -= x * tmp;
        x = t % mx;
        for (int i = 1; vec[i] <= x ; i++) {
            if (vec[i] - vec[i - 1] > v)
                ans--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}