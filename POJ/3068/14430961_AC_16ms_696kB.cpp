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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100;
const int maxm = 20400;
using namespace std;

int n, m, tol;
struct Node {
    int u;
    int v;
    int w;
    int val;
    int next;
};
Node node[maxm];
int head[maxn];
int dis[maxn];
int pre[maxn];
int cap[maxn];
bool vis[maxn];

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
    memset(cap, 0, sizeof cap);
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
    memset(vis, false, sizeof vis);
    memset(dis, inf, sizeof dis);
    memset(pre, inf, sizeof pre);
    pre[src] = src;
    dis[src] = 0;
    vis[src] = true;
    cap[src] = inf;
    queue<int > q;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(node[i].w && dis[v] > dis[u] + node[i].val) {
                dis[v] = dis[u] + node[i].val;
                cap[v] = min(cap[u], node[i].w);
                pre[v] = i;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(dis[des] == inf)		return false;
    flow += cap[des];
    cost += dis[des] * cap[des];
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
    if(flow < 2)	return -1;
    else	return cost;
}

int main() {
    int cas = 1;
    while(scanf("%d%d", &n, &m), n||m) {
        init();
        int src = 0;
        int des = n + 1;
        for(int i=1; i<=m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addnode(u + 1, v + 1, 1, w);
            addnode(v + 1, u + 1, 0, -w);
        }
        addnode(src, 1, 2, 0);
        addnode(1, src, 0, 0);
        addnode(n, des, 2, 0);
        addnode(des, n, 0, 0);
        int ans = MCMF(src, des);
		if(ans == -1)	printf("Instance #%d: Not possible\n", cas++);
		else	printf("Instance #%d: %d\n", cas++, ans);
    }
    return 0;
}
