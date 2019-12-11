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
const int maxn = 200010;
const int maxm = 400010;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
struct Node {
    int v, f, w;
    int next;
    bool operator < (Node a) const {
        return w > a.w;
    }
};
Node node[maxm];
int head[maxn];
bool vis[maxn];
int dis[maxn];

void init() {
    tol = 0;
    memset(vis, 0, sizeof vis);
    memset(dis, inf, sizeof dis);
    memset(head, -1, sizeof head);
}

void addnode(int u, int v, int f) {
    node[tol].v = v;
    node[tol].f = f;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dijkstra() {
    dis[1] = 0;
    priority_queue<Node > q;
    while(!q.empty()) q.pop();
    Node now;
    now.v = 1;
    now.f = 0;
    now.w = 0;
    q.push(now);
    while(!q.empty()) {
        now = q.top();
        q.pop();
        int u = now.v;
        if(vis[u])	continue;
        vis[u] = true;
        dis[u] = now.w;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(!vis[v]) {
                Node nex;
                nex.v = v;
                nex.f = node[i].f;
                nex.w = dis[u] + (node[i].f != now.f);
                q.push(nex);
            }
        }
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        int u, v, w;
        for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &w);
            addnode(u, v, w);
            addnode(v, u, w);
        }
        dijkstra();
        if(dis[n] == inf)    printf("-1\n");
        else    printf("%d\n", dis[n]);
    }
    return 0;
}
