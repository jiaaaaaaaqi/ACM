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
const int    maxn = 1e5 + 100;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll sum[maxn << 2];
ll smx[maxn << 2];
ll la1[maxn << 2];
ll la2[maxn << 2];
ll ans[maxn];
struct ASK{
    int l, r, id;
    bool operator < (ASK a) const {
        return r < a.r;
    }
} ask[maxn];
int a[maxn];
int vis[maxn << 1];

void init() {
    mes(a, 0);
    mes(vis, 0);
}

void pushup(int rt) {
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
    smx[rt] = max(smx[rt<<1], smx[rt<<1|1]);
}

void pushdown(int rt) {
    if(la1[rt] || la2[rt]) {
        la2[rt<<1] = max(la2[rt<<1], la2[rt] + la1[rt<<1]);
        smx[rt<<1] = max(smx[rt<<1], sum[rt<<1] + la2[rt]);
        la1[rt<<1] += la1[rt];
        sum[rt<<1] += la1[rt];

        la2[rt<<1|1] = max(la2[rt<<1|1], la2[rt] + la1[rt<<1|1]);
        smx[rt<<1|1] = max(smx[rt<<1|1], sum[rt<<1|1] + la2[rt]);
        la1[rt<<1|1] += la1[rt];
        sum[rt<<1|1] += la1[rt];

        la1[rt] = la2[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    sum[rt] = smx[rt] = la1[rt] = la2[rt] = 0;
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, int v, int rt) {
    if(pl <= l && r <= pr) {
        sum[rt] += v;
        la1[rt] += v;
        la2[rt] = max(la2[rt], la1[rt]);
        smx[rt] = max(smx[rt], sum[rt]);
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(pl <= mid)
        update(l, mid, pl, pr, v, rt<<1);
    if(pr > mid)
        update(mid+1, r, pl, pr, v, rt<<1|1);
    pushup(rt);
}

ll query(int l, int r, int pl, int pr, int rt) {
    if(pl <= l && r <= pr) {
        return smx[rt];
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(pl <= mid)
        ans = max(ans, query(l, mid, pl, pr, rt<<1));
    if(pr > mid)
        ans = max(ans, query(mid+1, r, pl, pr, rt<<1|1));
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        build(1, n, 1);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &ask[i].l, &ask[i].r);
            ask[i].id = i;
        }
        sort(ask+1, ask+1+m);
        int x = 1;
        for(int i=1; i<=n; i++) {
            if(x == m+1) break;
            update(1, n, 1, i, a[i], 1);
            vis[a[i]+maxn] = i;
            while(ask[x].r == i) {
                ans[ask[x].id] = query(1, n, ask[x].l, ask[x].r, 1);
                x++;
            }
        }
        for(int i=1; i<=m; i++) {
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}

/*
9
4 -2 -2 3 -1 -4 2 2 -6
3
1 2
1 5
4 9

*/