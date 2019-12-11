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

int n, m;
int cas, tol, T;

int fa[maxn << 1];
bool vis[maxn];
int aa[maxn];
int bb[maxn];

void init() {
    mes(vis, 0);
    for (int i = 1; i <= 2 * n; i++)
        fa[i] = i;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) {
        return ;
    } else {
        fa[x] = y;
        return ;
    }
}

int a, b;
bool check() {
    for (int i = 1; i <= a; i++) {
        int u = aa[i];
        for (int j = 1; j <= b; j++) {
            int v = bb[i];
            int x = find(u);
            int y = find(v);
            if (x == y)
                return false;
            x = find(u + n);
            y = find(v + n);
            if (x == y)
                return false;
        }
    }
    return true;
}

int main() {
    while (~scanf("%d%d%d%d", &n, &m, &a, &b)) {
        init();
        int u, v;
        while (m--) {
            scanf("%d%d", &u, &v);
            vis[u] = vis[v] = 1;
            bind(u, v + n);
            bind(v, u + n);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int x = find(i);
            int y = find(i + n);
            if (x == y) {
                flag = false;
                break;
            }
        }
        for (int i = 1; i <= a; i++) {
            scanf("%d", &aa[i]);
            vis[aa[i]] = 1;
        }
        for (int i = 1; i <= b; i++) {
            scanf("%d", &bb[i]);
            vis[bb[i]] = 1;
        }
        // printf("flag = %d\n", flag);
        if (!flag) {
            printf("NO\n");
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                printf("NO\n");
            }
            else {
                if (!check())
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
    }
    return 0;
}