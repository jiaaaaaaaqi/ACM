#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 300005;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int cnt;
struct Node {
    int u;
    int v;
    int next;
};
Node node[maxn << 1];
int head[maxn];
int dep[maxn];
int top[maxn];
int pos[maxn];
int son[maxn];
int fa[maxn];
int sz[maxn];
int sum[maxn << 2];
int maxx[maxn << 2];

void init() {
    tol = cnt = 0;
    memset(fa, 0, sizeof fa);
    memset(sz, 0, sizeof sz);
    memset(son, 0, sizeof son);
    memset(dep, 0, sizeof dep);
    memset(top, 0, sizeof top);
    memset(pos, 0, sizeof pos);
    memset(sum, 0, sizeof sum);
    memset(node, 0, sizeof node);
    memset(maxx, 0, sizeof maxx);
    memset(head, -1, sizeof head);
}

void addnode(int u, int v) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs1(int u, int f, int d) {
    son[u] = 0;
    fa[u] = f;
    dep[u] = d;
    sz[u] = 1;
    for(int i=head[u]; ~i; i=node[i].next) {
        int v = node[i].v;
        if(v == f)	continue;
        dfs1(v, u, d+1);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v])	son[u] = v;
    }
}

void dfs2(int u, int tp) {
    pos[u] = ++cnt;
    top[u] = tp;
    if(!son[u])	return ;
    dfs2(son[u], tp);
    for(int i=head[u]; ~i; i=node[i].next) {
        int v = node[i].v;
        if(v == fa[u] || v == son[u])	continue;
        dfs2(v, v);
    }
}

void pushup(int root) {
    maxx[root] = max(maxx[root << 1], maxx[root << 1 | 1]);
    sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void update(int left, int right, int p, int val, int root) {
    if(left == right) {
        maxx[root] = val;
        sum[root] = val;
        return ;
    }
    int mid = (left + right) >> 1;
    if(p <= mid)	update(left, mid, p, val, root << 1);
    else	update(mid+1, right, p, val, root << 1 | 1);
    pushup(root);
}

int query_max(int left, int right, int prel, int prer, int root) {
    if(prel <= left && right <= prer) {
        return maxx[root];
    }
    int mid = (left + right) >> 1;
    int ans = 0;
    if(prel <= mid)	ans = max(ans, query_max(left, mid, prel, prer, root << 1));
    if(prer > mid)	ans = max(ans, query_max(mid+1, right, prel, prer, root << 1 | 1));
    return ans;
}

int find_max(int x, int y) {
    int ans = -inf;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans = max(ans, query_max(1, n, pos[top[x]], pos[x], 1));
        x = fa[top[x]];
    }
    if(x != y) {
        if(dep[x] > dep[y])	swap(x, y);
        ans = max(ans, query_max(1, n, pos[x], pos[y], 1));
    } else {
        ans = max(ans, query_max(1, n, pos[x], pos[y], 1));
    }
    return ans;
}

int query_sum(int left, int right, int prel, int prer, int root) {
    if(prel <= left && right <= prer) {
        return sum[root];
    }
    int mid = (left + right) >> 1;
    int ans = 0;
    if(prel <= mid)	ans += query_sum(left, mid, prel, prer, root << 1);
    if(prer > mid)	ans += query_sum(mid+1, right, prel, prer, root << 1 | 1);
    return ans;
}

int find_sum(int x, int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans += query_sum(1, n, pos[top[x]], pos[x], 1);
        x = fa[top[x]];
    }
    if(x != y) {
        if(dep[x] > dep[y])	swap(x, y);
        ans += query_sum(1, n, pos[x], pos[y], 1);
    } else {
        ans = max(ans, query_sum(1, n, pos[x], pos[y], 1));
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i=1; i<n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addnode(u, v);
            addnode(v, u);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        for(int i=1; i<=n; i++) {
            int w;
            scanf("%d", &w);
            update(1, n, pos[i], w, 1);
        }
        int q;
        char s[10];
        scanf("%d", &q);
        while(q--) {
            scanf("%s", s);
            if(strcmp(s, "QMAX") == 0) {
                int l, r;
                scanf("%d%d", &l, &r);
                int ans = find_max(l, r);
                printf("%d\n", ans);
            } else if(strcmp(s, "QSUM") == 0) {
                int l, r;
                scanf("%d%d", &l, &r);
                int ans = find_sum(l, r);
                printf("%d\n", ans);
            } else if(strcmp(s, "CHANGE") == 0) {
                int p, val;
                scanf("%d%d", &p, &val);
                update(1, n, pos[p], val, 1);
            }
        }
    }
    return 0;
}
