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
const int    maxn = 2e6 + 10;
const int    maxm = 2e6 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int u, v;
    ll w;
    int next;
    bool operator < (Node a) const {
        return w > a.w;
    }
} node[maxm << 1];
int head[maxn];
ll dis[2][maxn];
bool vis[maxn];
int a[maxn];

void init() {
    tol = 0;
    mes(node, 0);
    mes(head, -1);
    mes(dis[0], inf);
    mes(dis[1], inf);
}

void addnode(int u, int v, ll w) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].w = w;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dijkstra(int s, int t, int flag) {
    mes(vis, 0);
    priority_queue<Node> q;
    while (!q.empty())   q.pop();
    dis[flag][s] = 0;
    Node now;
    now.v = s;
    now.w = 0;
    q.push(now);
    while (!q.empty()) {
        now = q.top();
        q.pop();
        int u = now.v;
        if (vis[u])  continue;
        vis[u] = true;
        dis[flag][u] = now.w;
        for (int i = head[u]; ~i; i = node[i].next) {
            int v = node[i].v;
            if (vis[v])  continue;
            Node nex;
            nex.v = v;
            nex.w = dis[flag][u] + node[i].w;
            q.push(nex);
        }
    }
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        int k, u;
        ll t;
        for (int i = 1; i <= m; i++) {
            scanf("%lld%d", &t, &k);
            while (k--) {
                scanf("%d", &u);
                addnode(u, n + i, t);
                addnode(n + i, u, t);
            }
        }
        dijkstra(1, n, 0);
        dijkstra(n, 1, 1);
        ll ans = inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, max(dis[0][i], dis[1][i]));
            // printf("%lld %lld\n", dis[0][i], dis[1][i]);
        }
        printf("Case #%d: ", cas++);
        if(ans == inf)  printf("Evil John\n");
        else {
            int cnt = 0;
            for(int i=1; i<=n; i++) {
                if(max(dis[0][i], dis[1][i]) == ans) {
                    a[++cnt] = i;
                }
            }
            printf("%d\n", ans/2);
            for(int i=1; i<=cnt; i++)
                printf("%d%c", a[i], i==cnt ? '\n' : ' ');
        }
    }
    return 0;
}