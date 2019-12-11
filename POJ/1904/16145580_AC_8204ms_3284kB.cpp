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
const int    maxn = 5000;
const int    maxm = 203000;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int top, cnt, stacksize;

struct Node {
    int u, v;
    int next;
} node[maxm];
int dfn[maxn];
int low[maxn];
int sta[maxn];
bool vis[maxn];
int head[maxn];
int belong[maxn];

int read() {
    int x = 0, f = 1;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-')    f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    return x * f;
}

void output(int x) {
    if (x > 9)
        output(x / 10);
    putchar(x % 10 + '0');
}

void init() {
    top = tol = cnt = stacksize = 0;
    mes(dfn, 0);
    mes(vis, 0);
    mes(low, 0);
    mes(sta, 0);
    mes(head, -1);
    mes(belong, 0);
}

void addnode(int u, int v) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u) {
    int v;
    low[u] = dfn[u] = ++cnt;
    vis[u] = true;
    sta[stacksize++] = u;
    for (int i = head[u]; ~i; i = node[i].next) {
        v = node[i].v;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        top++;
        do {
            v = sta[--stacksize];
            belong[v] = top;
            vis[v] = false;
        } while (v != u);
    }
}

void tarjan() {
    for (int i = 1; i <= 2 * n; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
}

void solve() {
    std::vector<int> vc;
    for (int u = 1; u <= n; u++) {
        vc.clear();
        for (int i = head[u]; ~i; i = node[i].next) {
            int v = node[i].v;
            if (belong[u] == belong[v]) {
                vc.push_back(v - n);
            }
        }
        sort(vc.begin(), vc.end());
        int len = vc.size();
        printf("%d ", len);
        for (int i = 0; i < len; i++) {
            printf("%d%c", vc[i], i == len - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    int q, x;
    for (int i = 1; i <= n; i++) {
        q = read();
        while (q--) {
            x = read();
            addnode(i, x + n);
        }
    }
    for (int i = 1; i <= n; i++) {
        x = read();
        addnode(x + n, i);
    }
    tarjan();
    // for (int i = 1; i <= 2 * n; i++) {
    //     printf("%d %d\n", i, belong[i]);
    // }
    solve();
    return 0;
}