/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月23日 星期五 15时49分37秒
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
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Path {
    int v;
    ll w;
    Path() {}
    Path(int xv, ll xw) {
        v = xv, w = xw;
    }
    bool operator < (Path a) const {
        return w<a.w;
    }
};
ll ans[maxn];
vector<Path> vv[maxn];
multiset<Path> st;
int ask[maxn];

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        st.clear();
        int q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i=1; i<=n; i++)    vv[i].clear();
        ll w;
        for(int i=1, u, v; i<=m; i++) {
            scanf("%d%d%lld", &u, &v, &w);
            vv[u].pb(Path(v, w));
        }
        for(int i=1; i<=n; i++)    sort(vv[i].begin(), vv[i].end());
        int mx = 0;
        for(int i=1; i<=q; i++) {
            scanf("%d", &ask[i]);
            mx = max(mx, ask[i]);
        }
        
        for(int i=1; i<=n; i++)    for(auto nex : vv[i]) {
            st.insert(Path(nex.v, nex.w));
            if(st.size() > mx) {
                auto it = st.end();
                it--;
                st.erase(it);
            }
        }

        int cnt = 0;
        while(cnt<mx) {
            Path it = (*st.begin());
            ans[++cnt] = it.w;
            st.erase(st.begin());
            for(auto nex : vv[(it).v]) {
                // st.insert(Path(nex.v, nex.w+it.w));
                if(st.size() == mx) {
                    auto itend = st.end();
                    itend--;
                    if((*itend).w > (nex.w+(it).w)) {
                        st.erase(itend);
                        st.insert(Path(nex.v, nex.w+(it).w));
                    } else    break;
                } else {
                    st.insert(Path(nex.v, nex.w+(it).w));
                }
            }
        }

        for(int i=1; i<=q; i++)    printf("%lld\n", ans[ask[i]]);
    }
    return 0;
}