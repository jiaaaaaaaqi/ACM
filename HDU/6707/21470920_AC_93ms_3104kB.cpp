/*************************************************************** 
    > File Name    : 1006.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月23日 星期五 12时25分13秒
 ***************************************************************/

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
#define  pb         push_back
#define  pii        pair<int, int>

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

int a[maxn];
bool vis[maxn];
vector<int> vv;

int main() {
    // freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    int x;
    vv.clear();
    while(m--) {
        scanf("%d", &x);
        vv.pb(x);
    }
    vector<int> ans;
    int len = vv.size();
    for(int i=len-1; i>=0; i--) {
        if(vis[vv[i]])    continue;
        ans.pb(vv[i]);
        vis[vv[i]] = 1;
    }
    for(int i=1; i<=n; i++) {
        if(vis[a[i]])    continue;
        ans.pb(a[i]);
        vis[a[i]] = 1;
    }
    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}