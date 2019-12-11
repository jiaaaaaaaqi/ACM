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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 105;
const int maxm = 10000;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
struct Node {
    int u;
    int v;
    int w;
    int val;
    int next;
};
Node node[maxm];
int head[maxm];
int dis[maxm];
int pre[maxm];
int cap[maxm];
bool vis[maxm];
int maps[maxn][maxn];

void init() {
    tol = 0;
    memset(node, 0, sizeof node);
    memset(maps, 0, sizeof maps);
    memset(head, -1, sizeof head);
}

void addnode(int u, int v, int w, int val) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].w = w;
    node[tol].val = val;
    node[tol].next = head[u];
    head[u] = tol++;
}

bool spfa(int src, int des, int &flow, int &cost) {
    memset(vis, 0, sizeof vis);
    memset(dis, inf, sizeof dis);
    memset(cap, inf, sizeof cap);
    queue<int > q;
    dis[src] = 0;
    cap[src] = inf;
    pre[src] = src;
    vis[src] = true;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(node[i].w && dis[v] > dis[u] + node[i].val) {
                dis[v] = dis[u] + node[i].val;
                pre[v] = i;
                cap[v] = min(cap[u], node[i].w);
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(dis[des] == inf)	return false;
    flow += cap[des];
    cost += cap[des] * dis[des];
    int u = des;
    while(u != src) {
        node[pre[u]].w -= cap[des];
        node[pre[u]^1].w += cap[des];
        u = node[pre[u]].u;
    }
    return true;
}

int MCMF(int src, int des) {
    int flow = 0;
    int cost = 0;
    while(spfa(src, des, flow, cost));
    return cost;
}

int main() {
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)	for(int j=1; j<=m; j++)	scanf("%d", &maps[i][j]);
        int src = 1, des = 2*n*m;
        /*
            addnode(src, 1, inf, 0);
            addnode(1, src, 0, 0);
            addnode(2*n*m, des, inf, 0);
            addnode(des, 2*n*m, 0, 0);
        */
        int cnt = n * m;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if((i==1 && j==1) || (i==n && j == m)) {
                    addnode((i-1)*m+j, (i-1)*m+j+cnt, 2, -maps[i][j]);
                    addnode((i-1)*m+j+cnt, (i-1)*m+j, 0, maps[i][j]);
                } else {
                    addnode((i-1)*m+j, (i-1)*m+j+cnt, 1, -maps[i][j]);
                    addnode((i-1)*m+j+cnt, (i-1)*m+j, 0, maps[i][j]);
                }
                if(i+1<=n) {
                    addnode((i-1)*m+j+cnt, i*m+j, 1, 0);
                    addnode(i*m+j, (i-1)*m+j+cnt, 0, 0);
                }
                if(j+1<=m) {
                    addnode((i-1)*m+j+cnt, (i-1)*m+j+1, 1, 0);
                    addnode((i-1)*m+j+1, (i-1)*m+j+cnt, 0, 0);
                }
            }
        }
        int ans = -MCMF(src, des) - maps[1][1] - maps[n][m];
        printf("%d\n", ans);
    }
    return 0;
}
