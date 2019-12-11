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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int v;
    int next;
} node[maxm];
struct Ans {
	int id;
	int cnt;
	bool operator < (Ans a) const {
		return cnt < a.cnt;
	}
};
int vis[maxn];
int deep[maxn];
int head[maxn];
int fa[maxn][20];
Ans ans[maxn];

void init() {
    tol = 1;
    mes(fa, 0);
    mes(vis, 0);
    mes(deep, 0);
    mes(head, -1);
}

void addnode(int u, int v) {
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u, int f, int d) {
    deep[u] = d;
    for(int i=head[u]; ~i; i=node[i].next) {
        int v = node[i].v;
        if(v == f)		continue;
        if(fa[v][0])	continue;
        fa[v][0] = u;
        dfs(v, u, d+1);
    }
}

void update() {
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    if(deep[u] < deep[v])	swap(u, v);
    int f = deep[u] - deep[v];
    for(int i=0; (1<<i)<=f; i++) {
        if(f & (1<<i)) {
            u = fa[u][i];
        }
    }
    if(u != v) {
        for(int i=int(log2(n)); i>=0; i--) {
            if(fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        u = fa[u][0];
    }
    return u;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        int u, v;
        for(int i=1; i<=n; i++) {
            scanf("%d:(%d)", &u, &m);
            while(m--) {
                scanf("%d", &v);
                addnode(u, v);
                addnode(v, u);
                vis[v]++;
            }
        }
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                fa[i][0] = i;
                dfs(i, i, 1);
                break;
            }
        }
        update();
        scanf("%d", &m);
        for(int i=1; i<=n; i++) {
			ans[i].id = ans[i].cnt = 0;
        }
        while(m--) {
            scanf(" (%d %d)", &u, &v);
            int x = lca(u, v);
			ans[x].id = x;
			ans[x].cnt++;
        }
        sort(ans+1, ans+1+n);
        for(int i=1; i<=n; i++) {
			if(ans[i].cnt == 0)	continue;
			printf("%d:%d\n", ans[i].id, ans[i].cnt);
        }
    }
    return 0;
}
