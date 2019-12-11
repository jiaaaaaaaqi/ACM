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
const int    maxn = 30;
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
    int x1, y1;
    int x2, y2;
} node[maxn];
struct Edge {
    int u, v;
    bool operator < (Edge a) const {
        return u > a.u;
    }
    Edge () {

    }
    Edge (int a, int b) {
        u = a, v = b;
    }
};
int maps[maxn][maxn];
bool vis[maxn];
int linker[maxn];
int tlinker[maxn];

void init() {
    mes(maps, 0);
    mes(node, 0);
    mes(linker, 0);
    mes(tlinker, 0);
}

bool ok(int i, int x, int y) {
    if (node[i].x1 < x && x < node[i].x2 && node[i].y1 < y && y < node[i].y2)
        return true;
    return false;
}

bool dfs(int u) {
    for (int v = 1; v <= n; v++) {
        if (maps[u][v] && !vis[v]) {
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
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main() {
    cas = 1;
    while (scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &node[i].x1, &node[i].x2, &node[i].y1, &node[i].y2);
        }
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            for (int j = 1; j <= n; j++) {
                if (ok(j, x, y)) {
                    maps[j][i] = 1;
                }
            }
        }
        int ans = match();
        printf("Heap %d\n", cas++);
        if (ans != n) {
            printf("none\n\n");
            continue;
        }
        memcpy(tlinker, linker, sizeof linker);
        bool flag = true;
        priority_queue<Edge> q;
        for (int i = 1; i <= n; i++) {
            maps[tlinker[i]][i] = 0;
            if (n != match()) {
                q.push(Edge(tlinker[i], i));
                flag = true;
            }
            maps[tlinker[i]][i] = 1;
        }
        if (!flag)   printf("none\n\n");
        else {
            while(!q.empty()) {
                Edge e = q.top();
                q.pop();
                printf("(%c,%d)", e.u-1+'A', e.v);
                if(q.size())   printf(" ");
            }
            printf("\n\n");
        }
    }
    return 0;
}