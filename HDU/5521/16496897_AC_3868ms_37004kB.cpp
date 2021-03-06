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
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int v, w;
    int next;
    bool operator < (Node a) const {
        return w > a.w;
    }
} node[maxn];
int head[maxn];
ll dis[2][maxn];
bool vis[maxn];
int a[maxn];

void init() {
    tol = 0;
    mes(head, -1);
    for(int i=0; i<=n+m+1; i++)
        dis[0][i] = dis[1][i] = inf;
}

void addnode(int u, int v, int w) {
    node[tol].v = v;
    node[tol].w = w;
    node[tol].next = head[u];
    head[u] = tol++;
}

void spfa(int st, int ed, int flag) {
    queue<int> q;
    vis[st] = true;
    dis[flag][st] = 0;
    q.push(st);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        if(u == ed) continue;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            int w = node[i].w;
            if(dis[flag][v] > dis[flag][u] + w) {
                dis[flag][v] = dis[flag][u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        init();
        int k, u, t;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &t, &k);
            while (k--) {
                scanf("%d", &u);
                addnode(u, n + i, t);
                addnode(n + i, u, 0);
            }
        }
        printf("Case #%d: ", cas++);
        spfa(1, n, 0);
        if (dis[0][n] == inf) {
            printf("Evil John\n");
            continue;
        }
        spfa(n, 1, 1);
        ll ans = inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, max(dis[0][i], dis[1][i]));
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (max(dis[0][i], dis[1][i]) == ans) {
                a[++cnt] = i;
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= cnt; i++)
            printf("%d%c", a[i], i == cnt ? '\n' : ' ');
    }
    return 0;
}