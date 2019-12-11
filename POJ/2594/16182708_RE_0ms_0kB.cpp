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
const int    maxn = 505;
const int    maxm = 5005;
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
    int next;
} node[maxm];
int head[maxm];
int vis[maxn];
int linker[maxn];
int g[maxn][maxn];

void init() {
    tol = 0;
    mes(g, 0);
    mes(head, -1);
    mes(linker, 0);
}

void addnode(int u, int v) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

bool dfs(int u) {
    for (int i = head[u]; ~i; i = node[i].next) {
        int v = node[i].v;
        if (!vis[v]) {
            vis[v] = true;
            if (!linker[v] || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        mes(vis, 0);
        if (dfs(i))  ans++;
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u][v] = 1;
        }
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(g[i][k] && g[k][j])
                        g[i][j] = 1;
                }
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(g[i][j])
                    addnode(i, j);
        printf("%d\n", n - match());
    }
    return 0;
}