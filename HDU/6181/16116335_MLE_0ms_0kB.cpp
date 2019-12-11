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

struct Edge {
    int u, v;
    ll  w;
    int next;
} edge[maxn];
struct Node {
    int u, g, h;
    bool operator < (Node a) const {
        return g + h > a.g + a.h;
    }
    Node () {

    }
    Node (int a, int b, int c) {
        u = a;
        g = b;
        h = c;
    }
};
int head[maxn];
bool vis[maxn];
ll dis[maxn];

void init() {
    tol = 0;
    mes(vis, 0);
    mes(head, -1);
    mes(dis, inf);
}

void addedge(int u, int v, ll w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void spfa(int s, int t) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            ll w = edge[i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int A_star(int s, int t, int k) {
    if(dis[s] == -1)    return -1;
    priority_queue<Node> q;
    q.push(Node(s, 0, dis[s]));
    int cnt = 0;
    while(!q.empty()) {
        Node now = q.top();
        q.pop();
        int u = now.u;
        if(u == t)  cnt++;
        if(cnt == k)    return now.g;
        for(int i=head[u]; ~i; i=edge[i].next) {
            Node tmp;
            tmp.u = edge[i].v;
            tmp.g = now.g + edge[i].w;
            tmp.h = dis[edge[i].v];
            q.push(tmp);
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        ll w;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%lld", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        spfa(n, 1);
        int ans = A_star(1, n, 2);
        printf("%d\n", ans);
    }
    return 0;
}