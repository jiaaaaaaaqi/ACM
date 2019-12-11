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

ll n, m;
int cas, tol, T;
char s[11];

int main() {
    while (1) {
        gets(s);
        if(s[0] == 'E')
            break;
        sscanf(s, "%lld%lld", &n, &m);
        n = abs(n);
        m = abs(m);
        if (n < m)
            swap(n, m);
        if (n == 1 && m == 1) {
            printf("2\n");
            continue;
        }
        if (n == 2 && m == 2) {
            printf("4\n");
            continue;
        }
        if (n == 1 && m == 0) {
            printf("3\n");
            continue;
        }
        ll tmp = n + m;
        if (n <= 2 * m) {
            ll ans = tmp / 3 + tmp % 3;
            printf("%lld\n", ans);
        } else {
            ll ans = m;
            n -= 2 * m;
            ll x = n % 4;
            ans += (n - x) / 2;
            ans += x;
            printf("%lld\n", ans);
        }
    }
    return 0;
}