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
const int maxn = 5100;
const int maxm = 100000;
const int mod = 1000000007;
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
int num[105][105];
int pre[maxn];
int dis[maxn];
int cap[maxn];
int head[maxn];
bool vis[maxn];

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
    memset(node, 0, sizeof node);
    memset(num, 0, sizeof num);
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
    pre[src] = src;
    vis[src] = 1;
    cap[src] = inf;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(node[i].w && dis[v] > dis[u] + node[i].val) {
                dis[v] = dis[u] + node[i].val;
                pre[v] = i;
                cap[v] = min(cap[u], node[i].w);
                if(!vis[v]) {
                    vis[v] = 1;
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
        node[pre[u] ^ 1].w += cap[des];
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
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &num[i][j]);
                num[i][j] *= -1;
            }
        }
        if(m == 0) {
			printf("0\n");
			continue;
        }
        int src = 0;
        int des = n * n * 2 + 1;
        int cnt = n * n + 1;
        addnode(src, 1, m, 0);
        addnode(1, src, 0, 0);
        addnode(n * n + cnt, des, m, 0);
        addnode(des, n * n + cnt, 0, 0);
        for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				int tmp = (i - 1) * n + j;
				addnode(tmp, tmp + cnt, 1, num[i][j]);
				addnode(tmp, tmp + cnt, 0, -num[i][j]);
				addnode(tmp, tmp + cnt, m-1, 0);
				addnode(tmp, tmp + cnt, 0, 0);
				if(i == n && j == n)	continue;
				int tmp2;
				if(i + 1 <= n) {
					tmp2 = i * n + j;
					addnode(tmp + cnt, tmp2, m, 0);
					addnode(tmp2, tmp + cnt, 0, 0);
				}
				if(j + 1 <= n) {
					tmp2 = (i - 1) * n + j + 1;
					addnode(tmp + cnt, tmp2, m, 0);
					addnode(tmp2, tmp + cnt, 0, 0);
				}
			}
        }
        int ans = MCMF(src, des);
        printf("%d\n", -ans);
    }
    return 0;
}
