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
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, s;
int cas, tol, T;

ll ans;
int path[11];
int maps[105][105];
std::vector<int> vec[105];

void init() {
    for (int i = 1; i <= n; i++)
        vec[i].clear();
    mes(maps, 0);
    ans = 0;
}

bool check(int a[], int n, int x) {
    for (int i = 1; i <= n; i++) {
        int u = a[i];
        if (!maps[u][x])
            return false;
    }
    return true;
}

void dfs(int u, int dep) {
    if (dep == s) {
        ans++;
        return ;
    }
    int len = vec[u].size();
    for (int i = 0; i < len; i++) {
        int v = vec[u][i];
        if (v < u)
            continue;
        if (check(path, dep, v)) {
            path[dep + 1] = v;
            dfs(v, dep + 1);
            path[dep + 1] = 0;
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &s);
        init();
        int u, v;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            maps[u][v] = maps[v][u] = 1;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for (int i = 1; i <= n - s + 1; i++) {
            path[1] = i;
            dfs(i, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}