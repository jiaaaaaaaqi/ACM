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

set<ull> st[2];
ull seed = 131;
struct Edge {
    int digit[11];
    bool vis[101];
} edge[2][1001];
int digit[11];
int tmp[11];
int maps[101][101];
int cnt[2];

void init() {
    st[0].clear();
    st[1].clear();
    mes(maps, 0);
    mes(cnt, 0);
}

ull Hash(int tmp[], int n) {
    ull ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans * seed + tmp[i];
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        int k;
        scanf("%d%d%d", &n, &m, &k);
        int f = 0;
        int u, v;
        cnt[f] = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            maps[u][v] = maps[v][u] = 1;
            if (u > v)
                swap(u, v);
            cnt[f]++;
            mes(edge[f][cnt[f]].vis, 0);
            edge[f][cnt[f]].digit[1] = u;
            edge[f][cnt[f]].digit[2] = v;
            edge[f][cnt[f]].vis[u] = 1;
            edge[f][cnt[f]].vis[v] = 1;
        }
        for (int len = 2; len <= k - 1; len++) {
            f = !f;
            cnt[f] = 0;
            st[f].clear();
            for (int i = 1; i <= cnt[!f]; i++) {
                memcpy(digit, edge[!f][i].digit, sizeof edge[!f][i].digit);
                for (int j = 1; j <= n; j++) {
                    if (edge[!f][i].vis[j])
                        continue;
                    bool flag = true;
                    for (int ii = 1; ii <= len; ii++) {
                        if (maps[digit[ii]][j] == 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        memcpy(tmp, digit, sizeof digit);
                        tmp[len + 1] = j;
                        sort(tmp + 1, tmp + len + 2);
                        ull ha = Hash(tmp, len + 1);
                        if (st[f].count(ha) == 0) {
                            st[f].insert(ha);
                            cnt[f]++;
                            for (int ii = 1; ii <= len + 1; ii++) {
                                // printf("%d ", tmp[ii]);
                                edge[f][cnt[f]].digit[ii] = tmp[ii];
                            }
                            // printf("\n");
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt[f]);
    }
    return 0;
}