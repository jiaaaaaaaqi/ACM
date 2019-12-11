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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 100040;
const int    maxm = 100005;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int T, tol;
struct Node {
    int u;
    int v;
    int next;
};
Node node[maxm];
int cnt, stasize, top;
int head[maxn];
int dfn[maxn];
int low[maxn];
int sta[maxn];
int ind[maxn];
int maps[maxn];
bool vis[maxn];

void init() {
    tol = cnt = stasize = top = 0;
    memset(node, 0, sizeof node);
    memset(maps, 0, sizeof maps);
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(sta, 0, sizeof sta);
    memset(ind, 0, sizeof ind);
}

void addnode(int u, int v) {
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u) {
    int v;
    dfn[u] = low[u] = ++cnt;
    vis[u] = true;
    sta[stasize++] = u;
    for(int i=head[u]; ~i; i=node[i].next) {
        v = node[i].v;
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        top++;
        do {
            v = sta[--stasize];
            maps[v] = top;
            vis[v] = false;
        } while(v != u);
    }
}

void tarjan() {
    for(int u=1; u<=n; u++) {
        if(!dfn[u]) {
            dfs(u);
        }
    }
}

int path[maxn];

void solve() {
    for(int u=1; u<=n; u++) {
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(maps[u] != maps[v]) {
                ind[maps[v]]++;
            }
        }
    }
    int x = 0;
    memset(path, 0, sizeof path);
    memset(vis, 0, sizeof vis);
    int sum = 0;
    for(int i=1; i<=n; i++) {
        if(ind[maps[i]] == 0) {
            if(!vis[maps[i]]) {
                vis[maps[i]] = true;
                x++;
            }
            path[sum++] = i;
        }
    }
    if(x != 1) {
        printf("Confused\n");
    } else {
        sort(path, path+sum);
        for(int i=0; i<sum; i++)	printf("%d\n", path[i]-1);
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i=1; i<=m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u++, v++;
            addnode(u, v);
        }
        tarjan();
        solve();
    }
    return 0;
}
