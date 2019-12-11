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

int main() {
    while (scanf("%d", &n) != EOF) {
        int x, ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            int cnt = 0, base = 1, num = 0;
            for (int j = 1; j <= 32; j++) {
                num += (x & 1) * base;
                base *= 2;
                cnt++;
                x /= 2;
                if (cnt % 8 == 0) {
                    cnt = 0;
                    base = 1;
                    if (num == 97) ans++;
                    num = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}