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
const int    maxn = 2e4 + 10;
const int    maxm = 1e6 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int b[maxn];
int sa[maxn];
int tp[maxn];
int rk[maxn];
int tax[maxm];
int height[maxn];

void rsort(int n, int m) {
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
    for (int w = 1, p = 0, i; p < n; w <<= 1, m = p) {
        for (p = 0, i = n - w + 1; i <= n; i++)    tp[++p] = i;
        for (i = 1; i <= n; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for (i = 2; i <= n; i++) rk[sa[i]] = cmp(tp, sa[i], sa[i - 1], w) ? p : ++p;
    }
    int j, k = 0;
    for (int i = 1; i <= n; height[rk[i++]] = k)
        for (k = k ? k - 1 : k, j = sa[rk[i] - 1]; a[j + k] == a[i + k]; k++);
}

bool ok(int x) {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (height[i] >= x) {
            ans++;
            if (ans + 1 >= m)
                return 1;
        } else {
            ans = 0;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int nn = unique(b + 1, b + 1 + n) - (b + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + 1 + nn, a[i]) - b;
    }
    SA(a, n, nn + 1);
    // for(int i=1; i<=n; i++)
    //     printf("sa[%d] = %d\n", i, sa[i]);
    // for (int i = 2; i <= n; i++)
    //     printf("!!!%d\n", height[i]);
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}