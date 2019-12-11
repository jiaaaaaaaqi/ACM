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
const int    maxn = 5e4 + 10;
const int    maxm = 2e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int block;
struct Ask {
    int l, r, id, op;
    bool operator < (Ask a) const {
        return l / block == a.l / block ? r < a.r : l / block < a.l / block;
    }
} ask[maxm];
int a[maxn];
ll cnt1[maxn];
ll cnt2[maxn];
ll res[maxn];
ll ans;

void init() {
    ans = 0;
    mes(res, 0);
}

void add(int x, int id) {
    x = a[x];
    ans -= cnt1[x] * cnt2[x];
    if (id == 1) {
        cnt1[x]++;
    } else {
        cnt2[x]++;
    }
    ans += cnt1[x] * cnt2[x];
}

void del(int x, int id) {
    x = a[x];
    ans -= cnt1[x] * cnt2[x];
    if (id == 1) {
        cnt1[x]--;
    } else {
        cnt2[x]--;
    }
    ans += cnt1[x] * cnt2[x];
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    block = sqrt(n);
    scanf("%d", &m);
    tol = 0;
    int l1, r1, l2, r2;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        ask[++tol].l = r1, ask[tol].r = r2, ask[tol].id = i, ask[tol].op = 1;
        ask[++tol].l = l1 - 1, ask[tol].r = l2 - 1, ask[tol].id = i, ask[tol].op = 1;
        ask[++tol].l = l1 - 1, ask[tol].r = r2, ask[tol].id = i, ask[tol].op = -1;
        ask[++tol].l = l2 - 1, ask[tol].r = r1, ask[tol].id = i, ask[tol].op = -1;
    }
    sort(ask + 1, ask + tol + 1);
    int L = 0;
    int R = 0;
    for (int i = 1; i <= tol; i++) {
        int l = ask[i].l, r = ask[i].r;
        int id = ask[i].id, op = ask[i].op;
        while (L < l)
            add(++L, 1);
        while (L > l)
            del(L--, 1);
        while (R < r)
            add(++R, 2);
        while (R > r)
            del(R--, 2);
        res[id] += (ans * op);
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", res[i]);
    return 0;
}