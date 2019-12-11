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
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e4 + 10;
const int    maxm = 2e4 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e17 + 100;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, T;

struct PATH {
    struct Node {
        int u, v, next;
        ll  w;
        bool operator < (Node a) const {
            return w > a.w;
        }
    } node[2][maxn];
    int tol[2];
    ll  dis[2][maxn];
    bool vis[maxn];
    int head[2][maxn];

    void init(int n) {
        tol[0] = tol[1] = 0;
        for(int i=1; i<=n; i++) {
            vis[i] = 0;
            head[0][i] = head[1][i] = -1;
            dis[0][i] = dis[1][i] = INF;
        }
    }

    void addnode(int id, int u, int v, ll w) {
        node[id][tol[id]].u = u;
        node[id][tol[id]].v = v;
        node[id][tol[id]].w = w;
        node[id][tol[id]].next = head[id][u];
        head[id][u] = tol[id]++;
    }

    void spfa(int id, int st, int ed) {
        queue<int> q;
        vis[st] = true;
        dis[id][st] = 0;
        q.push(st);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            if(u==ed)
                continue;
            for(int i=head[id][u]; ~i; i=node[id][i].next) {
                int v = node[id][i].v;
                ll  w = node[id][i].w;
                if(dis[id][v] > dis[id][u] + w) {
                    dis[id][v] = dis[id][u] + w;
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
} path;

struct MCMF {
    struct Node {
        int v, next;
        ll w;
    } node[maxm];
    int tol;
    int head[maxn];
    int dep[maxn];

    void init() {
        tol = 0;
        memset(head, -1, sizeof(head));
    }

    void addnode(int u, int v, ll w) {
        node[tol].v = v;
        node[tol].w = w;
        node[tol].next = head[u];
        head[u] = tol++;
    }
    bool bfs(int src, int des) {
        queue<int > q;
        memset(dep, -1, sizeof(dep));
        dep[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == des)    return true;
            for(int i = head[u]; ~i; i = node[i].next) {
                int v = node[i].v;
                if(dep[v] == -1 && node[i].w) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    ll dfs(int src, int des, ll flow) {
        if(src == des)    return flow;
        int ans = 0;
        for(int i = head[src]; ~i; i = node[i].next) {
            int v = node[i].v;
            if(dep[v] == dep[src] + 1 && node[i].w) {
                ll tmp = dfs(v, des, min(node[i].w, flow - ans));
                node[i].w -= tmp;
                node[i^1].w += tmp;
                ans += tmp;
                if(ans == flow)    return ans;
            }
        }
        if(!ans)    dep[src] = -2;
        return ans;
    }

    ll solve(int src, int des) {
        ll ans = 0;
        ll tmp;
        while(bfs(src, des)) {
            while((tmp = dfs(src, des, INF)) > 0)
                ans += tmp;
        }
        return ans;
    }
} mcmf;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        path.init(n);
        for(int i=1, u, v; i<=m; i++) {
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            path.addnode(0, u, v, w);
            path.addnode(1, v, u, w);
        }
        path.spfa(0, 1, n);
        path.spfa(1, n, 1);
        ll shortpath = INF;
        for(int i=1; i<=n; i++) {
            shortpath = min(shortpath, path.dis[0][i] + path.dis[1][i]);
        }
        mcmf.init();
        int src = 1, des = n;
        for(int i=0; i<m; i++) {
            int u = path.node[0][i].u;
            int v = path.node[0][i].v;
            int  w = path.node[0][i].w;
            if(path.dis[0][u] + path.dis[1][v] + w == shortpath) {
//                if(src != u) {
//                    mcmf.addnode(src, u, 1, -path.dis[0][u]);
//                    mcmf.addnode(u, src, 0, path.dis[0][u]);
//                    printf("!!!%d %d %lld\n", src, u, path.dis[0][u]);
//                }
                mcmf.addnode(u, v, w);
                mcmf.addnode(v, u, 0);
//                printf("%d %d %d\n", u, v, w);
//                if(des != v) {
//                    mcmf.addnode(v, des, 1, -path.dis[1][v]);
//                    mcmf.addnode(des, v, 0, path.dis[1][v]);
//                    printf("!!!%d %d %lld\n", v, des, path.dis[1][u]);
//                }
            }
        }
        printf("%lld\n", mcmf.solve(src, des));
    }
    return 0;
}