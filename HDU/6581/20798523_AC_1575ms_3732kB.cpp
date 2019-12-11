#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll l[maxn], s[maxn], v[maxn];

int main() {
    while(~scanf("%d", &n)) {
        double ans = 0.0;
        double len = 0;
        for(int i=0; i<=n; i++) {
            scanf("%lld", &l[i]);
            len += l[i];
        }
        len -= l[0];
        for(int i=0; i<=n; i++)    scanf("%lld", &s[i]);
        for(int i=0; i<=n; i++)    scanf("%lld", &v[i]);
        for(int i=n; i>=0; i--) {
            ans = max(ans, 1.0*(s[i]+len)/v[i]);
            len -= l[i];
        }
        printf("%.7f\n", ans);
    }
    return 0;
}