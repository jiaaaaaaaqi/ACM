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
const int    maxn = 60;
const int    maxm = 1e3;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int ni, nj;

char s[maxn][maxn];
int g[maxn][maxn];
int g1[maxn][maxn];
int g2[maxn][maxn];
int maps[maxm][maxm];
int linker[maxm];
int vis[maxm];

void init() {
    mes(s, 0);
    mes(g, 0);
    mes(g1, 0);
    mes(g2, 0);
    mes(maps, 0);
    mes(linker, 0);
}

bool dfs(int u) {
    for(int v=1; v<=nj; v++) {
        if(maps[u][v] && !vis[v]) {
            vis[v] = true;
            if(!linker[v] || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match() {
    int ans = 0;
    for(int i=1; i<=ni; i++) {
        mes(vis, 0);
        if(dfs(i))
            ans++;
    }
    return ans;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%s", s[i]+1);
    ni = nj = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i][j] == '.')   continue;
            ni++;
            while(1) {
                if(j > m || s[i][j] == '.') 
                    break;
                g1[i][j] = ni;
                j++;
            }
        }
    }
    for(int j=1; j<=m; j++) {
        for(int i=1; i<=n; i++) {
            if(s[i][j] == '.')  continue;
            nj++;
            while(1) {
                if(i > n || s[i][j] == '.')
                    break;
                g2[i][j] = nj;
                i++;
            }
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) 
            if(s[i][j] == '.')  
                continue;
            else
                maps[g1[i][j]][g2[i][j]] = 1;
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         printf("%d%c", g2[i][j], j==m ? '\n' : ' ');
    //     }
    // }
    int ans = match();
    printf("%d\n", ans);
    return 0;
}