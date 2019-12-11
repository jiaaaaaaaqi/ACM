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
const int maxn = 1000;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int cnt;
struct Node {
    int u;
    int v;
    int w;
    int val;
    int next;
};
Node node[maxm];
int head[maxn];
int maps[35][35];
int dis[maxn];
int pre[maxn];
int cap[maxn];
bool vis[maxn];

void init() {
    tol = cnt = 0;
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

void dfs(int pos, int sum, int ans) {
	if(sum > ans)	return ;
	if(pos > n) {
		if(sum == ans) {
			printf("Best Pairing %d\n", ++cnt);
			for(int i=1; i<=n; i++) 
				printf("Supervisor %d with Employee %d\n", i, pre[i] - n);
			return ;
		}
		return ;
	}
	for(int i=n+1; i<=2*n; i++) {
		if(!pre[i]) {
			pre[i] = 1;
			pre[pos] = i;
			dfs(pos+1, sum + maps[pos][i], ans);
			pre[i] = 0;
			pre[pos] = 0;
		}		
	}
}

int main() {
    int T;
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int k;
                scanf("%d", &k);
                maps[k][i+n] += j-1;
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int k;
                scanf("%d", &k);
                maps[i][k+n] += j-1;
            }
        }
        int src = 0, des = n + n + 1;
        for(int i=1; i<=n; i++) {
            addnode(src, i, 1, 0);
            addnode(i, src, 0, 0);
        }
        for(int i=n+1; i<=n+n; i++) {
            addnode(i, des, 1, 0);
            addnode(des, i, 0, 0);
        }
        for(int i=1; i<=n; i++) {
            for(int j=n+1; j<=n+n; j++) {
                addnode(i, j, 1, maps[i][j]);
                addnode(j, i, 0, -maps[i][j]);
            }
        }
        int ans = MCMF(src, des);
        double res = (double)ans / (2 * n);
        printf("Data Set %d, Best average difference: %.6f", cas++, res);
        memset(pre, 0, sizeof pre);
        dfs(1, 0, ans);
    }
    return 0;
}

