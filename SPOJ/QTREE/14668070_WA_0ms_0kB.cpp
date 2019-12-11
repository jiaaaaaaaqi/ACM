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
const int maxn = 10005;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int cnt;
struct Edge {
    int u;
    int v;
    int w;
};
Edge edge[maxn];
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
int maxx[maxn << 2];

void init() {
    tol = cnt = 0;
    memset(fa, 0, sizeof fa);
    memset(sz, 0, sizeof sz);
    memset(son, 0, sizeof son);
    memset(dep, 0, sizeof dep);
    memset(top, 0, sizeof top);
    memset(pos, 0, sizeof pos);
    memset(edge, 0, sizeof edge);
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

void dfs1(int u, int fat, int d) {
    dep[u] = d;
    son[u] = 0;
    sz[u] = 1;
    fa[u] = fat;
    for(int i=head[u]; ~i; i=node[i].next) {
        int v = node[i].v;
        if(v == fat)	continue;
        dfs1(v, u, d+1);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp;
    pos[u] = ++cnt;
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
}

void update(int left, int right, int pos, int val, int root) {
    if(left == right) {
        if(left == pos)
            maxx[root] = val;
        return ;
    }
    int mid = (left + right) >> 1;
    if(pos <= mid)	update(left, mid, pos, val, root << 1);
    else	update(mid + 1, right, pos, val, root << 1 | 1);
    pushup(root);
}

int query(int left, int right, int prel,int prer, int root) {
    if(prel <= left && right <= prer) {
        return maxx[root];
    }
    int mid = (left + right) >> 1;
    int ans = 0;
    if(prel <= mid)
        ans = max(ans, query(left, mid, prel, prer, root << 1));
    if(prer > mid)
        ans = max(ans, query(mid + 1, right, prel, prer, root << 1 | 1));
    return ans;
}

int find(int a, int b) {
    int ans = -inf;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]])
            swap(a, b);
        ans = max(ans, query(1, n, pos[top[a]], pos[a], 1));
        a = fa[top[a]];
    }
    if(a != b) {
        if(dep[a] > dep[b])
            swap(a, b);
        ans = max(ans, query(1, n, pos[a], pos[b], 1));
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        init();
        for(int i=1; i<n; i++) {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
            addnode(edge[i].u, edge[i].v);
            addnode(edge[i].v, edge[i].u);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        for(int i=1; i<n; i++) {
            if(dep[edge[i].u] > dep[edge[i].v])	swap(edge[i].u, edge[i].v);
            update(1, n, pos[edge[i].v], edge[i].w, 1);
        }
        char str[20];
        while(1) {
            scanf("%s", str);
            if(str[0] == 'Q') {
                int x, y;
                scanf("%d%d", &x, &y);
                int ans = find(x, y);
                printf("%d\n", ans);
            } else if(str[0] == 'C') {
                int x, y;
                scanf("%d%d", &x, &y);
                update(1, n, pos[edge[x].v], y, 1);
            } else break;
        }
    }
    return 0;
}
