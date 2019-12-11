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
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
ll a[150], b[15];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
int fib[105];
int main() {
    fib[1] = 1;
    fib[2] = 2;
    int ans;
    for (int i = 3; i <= 20; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d",&n);
        if (n <= 3) {
            printf("Case #%d: %d\n", ++kase, 0);
            continue;
        }
        for (int i = 1; i <= 20; i++) {
            if (fib[i] > n) {
                ans = i-1;
                break;
            }
        }
        printf("Case #%d: %d\n", ++kase, n-ans);
    }
    return 0;
}
