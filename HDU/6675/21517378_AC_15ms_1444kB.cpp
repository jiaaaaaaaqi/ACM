#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[45][55];
bool vis[55];
vector<int> vv[55];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        mes(vis, 0);
        for(int i=1; i<=m; i++)    vv[i].clear();
        n *= 2;
        for(int i=1; i<=n; i++) {
            scanf("%s", s[i]+1);
        }
        int len = strlen(s[1]+1);
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=m; j++) {
                int flag = true;
                for(int k=1; k<=n; k+=2) {
                    if(s[k][i] != s[k+1][j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    vv[i].push_back(j);
            }
        }
        vector<int> ans;
        bool flag = true;
        for(int i=1; i<=m; i++) {
            bool f = false;
            for(auto v : vv[i]) {
                if(vis[v])    continue;
                ans.push_back(v);
                vis[v] = true;
                f = true;
                break;
            }
            if(!f)    flag = false;
        }
        if(!flag)    printf("-1\n");
        else {
            for(int i=0; i<ans.size(); i++) {
                printf("%d%c", ans[i], i==ans.size()-1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}