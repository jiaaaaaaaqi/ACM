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
const int maxn = 1005;
const int maxm = 10000;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
int cnt, top, sz;
struct Edge {
    int x;
    int y;
    int r;
    int w;
};
struct Node {
    int u;
    int v;
    int next;
};
Node node[maxm];
Edge edge[maxn];
int head[maxm];
int dfn[maxn];
int low[maxn];
int fath[maxn];
int sta[maxm];
bool vis[maxn];
int point[maxn];
int ind[maxn];
int cost[maxn];

void init() {
    cnt = tol= top = sz = 0;
    memset(ind, 0, sizeof ind);	
    memset(sta, 0, sizeof sta);
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(fath, 0, sizeof(fath));
    memset(head, -1, sizeof(head));
    memset(cost, inf, sizeof cost);
    memset(point, 0, sizeof point);
    memset(vis, false, sizeof(vis));
}

double calc(int i, int j) {
    int x1 = edge[i].x;
    int x2 = edge[j].x;
    int y1 = edge[i].y;
    int y2 = edge[j].y;
    int ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return ans;
}

void addnode(int u, int v) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	sta[sz++] = u;
	vis[u] = true;
	for(int i=head[u]; ~i; i=node[i].next) {
		v = node[i].v;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		++top;
		do{
			v = sta[--sz];
			vis[v] = false;
			point[v] = top;
		} while(v != u);
	}
}

void tarjan() {
    for(int u=1; u<=n; u++) {
        if(!dfn[u])	dfs(u);
    }
}

void solve() {
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(point[u] != point[v])	ind[point[v]]++;
		}
	}
}

int main() {
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++)	scanf("%d%d%d%d", &edge[i].x, &edge[i].y, &edge[i].r, &edge[i].w);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j)	continue;
                int a = edge[i].r * edge[i].r;
                int b = calc(i, j);
                if(a >= b)	addnode(i, j);
            }
        }
        tarjan();
//        for(int i=1; i<=n; i++)	printf("%d %d\n", i, point[i]);
		solve();
//        for(int i=1; i<=top; i++)	printf("%d %d\n", i, ind[i]);
        ll ans = 0;
        for(int i=1; i<=n; i++) {
			if(!ind[point[i]]) {
				if(cost[point[i]] != inf)
					ans -= cost[point[i]];
				cost[point[i]] = min(cost[point[i]], edge[i].w);
				ans += cost[point[i]];
			}
        }
		printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
