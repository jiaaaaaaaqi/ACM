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
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
char s[maxn];
int sa[maxn];
int rk[maxn];
int tp[maxn];
int tax[maxn];
int height[maxn];

void init() {
    mes(sa, 0);
    mes(rk, 0);
    mes(tp, 0);
    mes(tax, 0);
    mes(height, 0);
}

int rsort(int n, int m) {
    for (int i = 0; i <= m; i++) tax[i] = 0;
    for (int i = 1; i <= n; i++) tax[rk[tp[i]]]++;
    for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
    return f[x] == f[y] && f[x + w] == f[y + w];
}

void SA(int *a, int n, int m) {
    for (int i = 1; i <= n; i++) rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for (int w = 1, p = 0, i; p < n; m = p, w <<= 1) {
        for (p = 0, i = n - w + 1; i <= n; i++)     tp[++p] = i;
        for (i = 1; i <= n; i++) if (sa[i] > w)     tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for (i = 2; i <= n; i++) rk[sa[i]] = cmp(tp, sa[i], sa[i - 1], w) ? p : ++p;
    }
    int j, k = 0;
    for (int i = 1; i <= n; height[rk[i++]] = k)
        for (k = k ? k - 1 : k, j = sa[rk[i] - 1]; a[i + k] == a[j + k]; k++);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int mx = 0;
        for (int i = 1; i <= len; i++) {
            a[i] = s[i];
            mx = max(mx, a[i]);
        }
        SA(a, len, mx);
        int ans = 0;
        for (int i = 1; i <= len; i++) {
            ans += len - sa[i] + 1 - height[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}