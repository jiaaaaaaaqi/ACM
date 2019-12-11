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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;
int n, m;
int cas, tol, T;

int a[maxn * 3];
char s[maxn * 3];
int wa[maxn * 3];
int wb[maxn * 3];
int Ws[maxn * 3];
int wv[maxn * 3];
int sa[maxn * 3];
int rk[maxn * 3];
int height[maxn * 3];

void init() {
    mes(sa, 0);
    mes(rk, 0);
    mes(wa, 0);
    mes(wb, 0);
    mes(wv, 0);
    mes(Ws, 0);
    mes(height, 0);
}
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int c0(int *r, int a, int b) {
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b) {
    if (k == 2)
        return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
    else return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
}
void sort(int *r, int *a, int *b, int n, int m) {
    int i;
    for (i = 0; i < n; i++) wv[i] = r[a[i]];
    for (i = 0; i < m; i++) Ws[i] = 0;
    for (i = 0; i < n; i++) Ws[wv[i]]++;
    for (i = 1; i < m; i++)Ws[i] += Ws[i - 1];
    for (int i = n - 1; i >= 0; i--)
        b[--Ws[wv[i]]] = a[i];
}
void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)    dc3(rn, san, tbc, p);
    else for (i = 0; i < tbc; i++)  san[rn[i]] = i;
    for (i = 0; i < tbc; i++)   if (san[i] < tb)    wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)   wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++) sa[p] = wa[i++];
    for (; j < tbc; p++)sa[p] = wb[j++];
}
//a和sa也要开三倍
void da(int a[], int sa[], int rk[], int height[], int n, int m) {
    for (int i = n; i < 3 * n; i++)
        a[i] = 0;
    dc3(a, sa, n + 1, m);
    int i, j, k = 0;
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (a[i + k] == a[j + k])k++;
        height[rk[i]] = k;
    }
}

int main() {
    while (1) {
        init();
        scanf("%s", s);
        if (s[0] == '.') break;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            a[i] = s[i];
        a[len] = 0;
        da(a, sa, rk, height, len, 300);
        int ans = len - height[rk[0]];
        printf("%d\n", len % ans ? 1 : len / ans);
    }
    return 0;
}