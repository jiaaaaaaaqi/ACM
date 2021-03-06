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

int a[maxn];
int b[maxn];
char s[maxn];
int sa[maxn];
int rk[maxn];
int tp[maxn];
int tax[maxn];
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

void SA(int a[], int n, int m) {
    for (int i = 1; i <= n; i++) rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for (int w = 1,  p = 1, i; p < n; w <<= 1, m = p) {
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

bool judge(int x) {
    int mx = -inf, mn = inf;
    for(int i=2; i<=n; i++) {
        if(height[i] >= x) {
            mx = max(mx, max(sa[i], sa[i-1]));
            mn = min(mn, min(sa[i], sa[i-1]));
            if(mx - mn > x) return 1;
        } else {
            mx = -inf;
            mn = inf;
        }
    }
    return 0;
}

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        n--;
        for (int i = 1; i <= n; i++)
            b[i] = a[i + 1] - a[i] + 88;
        m = 176;
        SA(b, n, m);
        int l = 4, r = n;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (judge(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ++ans);
    }
    return 0;
}