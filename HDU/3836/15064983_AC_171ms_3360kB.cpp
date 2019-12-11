#include<map>
#include<set>
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
const int maxn = 20005;
const int maxm = 50005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
int cnt, sz, top;
struct Node {
    int u, v;
    int next;
};
Node node[maxm];
int head[maxn];
int dfn[maxn];
int low[maxn];
int ind[maxn];
int oud[maxn];
int sta[maxn];
int point[maxn];
bool vis[maxn];

void init() {
    tol = cnt = top = sz = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(ind, 0, sizeof ind);
    memset(oud, 0, sizeof oud);
    memset(vis, 0, sizeof vis);
    memset(head, -1, sizeof head);
    memset(point, 0, sizeof point);
}

void addnode(int u, int v) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u) {
    int v;
    dfn[u] = low[u] = ++cnt;
    sta[sz++] = u;
    vis[u] = true;
    for(int i=head[u]; ~i; i=node[i].next) {
        v = node[i].v;
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        ++top;
        do {
            v = sta[--sz];
            vis[v] = false;
            point[v] = top;
        } while(v != u);
    }
}

void tarjan() {
    for(int u=1; u<=n; u++) {
        if(!dfn[u])	dfs(u);
    }
}
/*
void solve() {
    for(int u=1; u<=n; u++) {
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(point[u] != point[v]) {
                ind[point[v]]++;
                oud[point[u]]++;
            }
        }
    }
}
*/
void solve() {
    for(int u=1; u<=n; u++) {
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(point[u] != point[v]) {
				ind[point[v]]++;
				oud[point[u]]++;
            }
        }
    }
}
int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        int u, v;
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &u, &v);
            addnode(u, v);
        }
        tarjan();
//        for(int i=1; i<=n; i++)	printf("!!!!%d %d\n", i, point[i]);
        if(top == 1) {
            printf("0\n");
            continue;
        }
        solve();
        int ans1=0, ans2=0;
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=top; i++) {
            if(ind[i] == 0)	ans1++;
            if(oud[i] == 0)	ans2++;
        }
        printf("%d\n", max(ans1, ans2));
    }
    return 0;
}
