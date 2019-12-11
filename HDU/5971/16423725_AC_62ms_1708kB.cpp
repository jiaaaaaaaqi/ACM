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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, a, b;
int cas, tol, T;
int good[maxn],  bad[maxn];
int vis[maxn];
int mark[maxn];
vector <int> mat[maxn];

bool dfs(int u, int deep) {
    if (deep) vis[u] = 1;
    else vis[u] = -1;

    int len = mat[u].size();
    for (int i = 0; i < len; i++) {
        int v = mat[u][i];
        if (vis[v] == 0) {
            if (!dfs(v, !deep)) return false;
        }
        else if (vis[u] + vis[v] != 0) return false;
    }
    return true;
}

void init() {
    for(int i=0; i<=n; i++) mat[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(mark, 0, sizeof(mark));
    memset(good, 0, sizeof(good));
    memset(bad, 0, sizeof(bad));
}

int main() {
    while (~scanf("%d%d%d%d", &n, &m, &a, &b)) {
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            mat[u].push_back(v);
            mat[v].push_back(u);
            mark[u] = mark[v] = 1;
        }
        for (int i = 1; i <= a; i++) {
            int x;
            scanf("%d", &x);
            good[i] = x;
            vis[x] = 1;
        }
        for (int i= 1; i <= b; i++) {
            int x;
            scanf("%d", &x);
            bad[i] = x;
            vis[x] = -1;
        }
        int flag = 1;
        for (int i = 1; i <= a; i++) {
            if (!dfs(good[i], 1)) {
                flag = 0;
                break;
            }
        }
        for (int i = 1; i <= b; i++) {
            if (!dfs(bad[i], 0)) {
                flag = 0;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && mark[i]) {
                if (!dfs(i, 1)) {
                    flag = 0;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                flag = 0;
                break;
            }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}