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
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int l, r;
    int cnt;
} node[maxn*40];
int rt[maxn];
int a[maxn];

void update(int l, int r, int &x, int y, int pos) {
    tol++;
    node[tol] = node[y];
    node[tol].cnt++;
    x = tol;
    if(l == r)    return ;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l, mid, node[x].l, node[y].l, pos);
    else
        update(mid+1, r, node[x].r, node[y].r, pos);
}

ll query(int l, int r, int x, int y, int k) {
    if(l == r) {
        if(node[y].cnt - node[x].cnt > 0)    return l;
        else    return inf;
    }
    if(l >= k) {
        int mid = l+r>>1;
        int cnt = node[node[y].l].cnt - node[node[x].l].cnt;
        if(cnt > 0)    return query(l, mid, node[x].l, node[y].l, k);
        else    return query(mid+1, r, node[x].r, node[y].r, k);
    } else {
        int mid = l+r>>1;
        int ans;
        if(k <= mid) {
            ans = query(l, mid, node[x].l, node[y].l, k);
            if(ans == inf)
                ans = query(mid+1, r, node[x].r, node[y].r, k);
            return ans;
        } else {
            ans = query(mid+1, r, node[x].r, node[y].r, k);
            return ans;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        tol = 0;
        scanf("%d%d", &n, &m);
        mes(node, 0);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        a[n+1] = n+1;n++;
        int mx = n;
        for(int i=1; i<=n; i++) {
            update(1, mx, rt[i], rt[i-1], a[i]);
        }
        ll ans = 0;
        int id, l, k;
        while(m--) {
            scanf("%d", &id);
            if(id == 1) {
                scanf("%d", &l);
                l = l^ans;
                n++;
                update(1, mx, rt[n], rt[n-1], a[l]);
            } else {
                scanf("%d%d", &l, &k);
                l = l^ans, k = k^ans;
                ans = query(1, mx, rt[l], rt[n], k);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}