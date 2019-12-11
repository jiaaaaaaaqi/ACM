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
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int t;
    int x1, y1;
    int x2, y2;
} node[maxn];
int maps[maxn][maxn];
int linker[maxn];
int vis[maxn];

void init() {
    mes(maps, 0);
    mes(linker, 0);
}

bool ok(int i, int j) {
    int a = abs(node[i].x1 - node[i].x2);
    int b = abs(node[i].y1 - node[i].y2);
    if (node[i].t + a + b < node[j].t)
        return true;
    return false;
}

bool dfs(int u) {
    for (int v = 1; v <= n; v++) {
        if (maps[u][v] && !vis[v]) {
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
        if (dfs(i)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        char s[10];
        for (int i = 1; i <= n; i++) {
            scanf("%s%d%d%d%d", s, &node[i].x1, &node[i].y1, &node[i].x2, &node[i].y2);
            int a, b;
            sscanf(s, "%d:%d", &a, &b);
            node[i].t = a * 60 + b;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ok(i, j)) {
                    maps[i][j] = 1;
                }
            }
        }
        int ans = match();
        printf("%d\n", n - ans);
    }
    return 0;
}