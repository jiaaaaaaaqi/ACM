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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[5][5];
bool vis[5][5];
int ans;

void init() {
    ans = 0;
    mes(s, 0);
}

bool check(int i, int j) {
    for (int k = i + 1; k <= n; k++) {
        if (s[k][j] == 'X')  break;
        if (vis[k][j])
            return false;
    }
    for (int k = i - 1; k >= 1; k--) {
        if (s[k][j] == 'X')  break;
        if (vis[k][j])
            return false;
    }
    for (int k = j + 1; k <= n; k++) {
        if (s[i][k] == 'X')  break;
        if (vis[i][k])
            return false;
    }
    for (int k = j - 1; k >= 1; k--) {
        if (s[i][k] == 'X')  break;
        if (vis[i][k])
            return false;
    }
    return true;
}

void dfs(int ni, int nj, int res) {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '.' && !vis[i][j]) {
                if(!check(i, j))
                    continue;
                flag = true;
                vis[i][j] = 1;
                dfs(i, j, res + 1);
                vis[i][j] = 0;
            }
        }
    }
    if (!flag) {
        ans = max(ans, res);
        return ;
    }
}

int main() {
    while (scanf("%d", &n), n) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == '.') {
                    mes(vis, 0);
                    vis[i][j] = 1;
                    dfs(i, j, 1);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}