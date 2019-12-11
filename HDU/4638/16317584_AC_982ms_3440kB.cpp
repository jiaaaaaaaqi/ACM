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

int n, m;
int cas, tol, T;
int block;
struct ASK {
    int l, r, id;
    bool operator < (ASK a) const {
        return l / block == a.l / block ? r < a.r : l / block < a.l / block;
    }
} ask[maxn];
int a[maxn];
int res[maxn];
bool vis[maxn];
int ans;

void init() {
    mes(a, 0);
    mes(ask, 0);
    mes(res, 0);
    mes(vis, 0);
}

void add(int x) {
    vis[a[x]] = 1;
    int l = a[x] - 1;
    int r = a[x] + 1;
    int cnt = 0;
    if (vis[l])    cnt++;
    if (vis[r])    cnt++;
    if (cnt == 0)    ans++;
    if (cnt == 2)    ans--;
}

void del(int x) {
    vis[a[x]] = 0;
    int l = a[x] - 1;
    int r = a[x] + 1;
    int cnt = 0;
    if (vis[l])    cnt++;
    if (vis[r])    cnt++;
    if(cnt == 0)    ans--;
    if(cnt == 2)    ans++;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        block = sqrt(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &ask[i].l, &ask[i].r);
            ask[i].id = i;
        }
        sort(ask + 1, ask + 1 + m);
        int L = 1, R = 0;
        ans = 0;
        for (int i = 1; i <= m; i++) {
            int l = ask[i].l;
            int r = ask[i].r;
            int id = ask[i].id;
            while (L > l)
                add(--L);
            while (R < r)
                add(++R);
            while (L < l)
                del(L++);
            while (R > r)
                del(R--);
            res[id] = ans;
        }
        for(int i=1; i<=m; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}